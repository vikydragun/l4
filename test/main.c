#define CTEST_MAIN

#include <ctest.h>
#include "uheader.h"

char A[10][10];

CTEST(enter_coor, PAWN_CORRECT) // a2 a3 
{
	bool result = move(7, 1, 6, 1, A);
	ASSERT_TRUE(result);
}

CTEST(enter_coor, PAWN_INCORRECT) // a2 a7
{
	bool result = move(7, 1, 2, 1, A);
	ASSERT_FALSE(result);
}

CTEST(enter_coor, ROOK_INCORRECT) // h1 h2
{
	bool result = move(8, 1, 8, 2, A);
	ASSERT_FALSE(result);
}

CTEST(enter_coor, KNIGHT_CORRECT) // b1 c3
{
	bool result = move(8, 2, 6, 3, A);
	ASSERT_TRUE(result);
}

CTEST(enter_coor, KNIGHT_INCORRECT) // b1 b2
{
	bool result = move(8, 2, 7, 2, A);
	ASSERT_FALSE(result);
}

CTEST(enter_coor, BISHOP_INCORRECT) // c1 b2
{
	bool result = move(8, 3, 7, 2, A);
	ASSERT_FALSE(result);
}

CTEST(enter_coor, QUEEN_INCORRECT) // d1 c1
{
	bool result = move(8, 4, 8, 3, A);
	ASSERT_FALSE(result);
}

CTEST(enter_coor, KING_INCORRECT) // e1 e2
{
	bool result = move(8, 5, 7, 5, A);
	ASSERT_FALSE(result);
}

int main(int argc, const char** argv)
{
	layout(A);
    return ctest_main(argc, argv);
}
