#include <bits/stdc++.h>

using namespace std;

namespace program
{
	const int N = 9, M = 3;
	const int X1[N] = { 0, 0, 0, 3, 3, 3, 6, 6, 6 };
	const int Y1[N] = { 0, 3, 6, 0, 3, 6, 0, 3, 6 };
	const int X2[N] = { 2, 2, 2, 5, 5, 5, 8, 8, 8 };
	const int Y2[N] = { 2, 5, 8, 2, 5, 8, 2, 5, 8 };
	const int State[N][N] = 
	{
		{ 0, 1, 2 , 0, 1, 2, 0, 1, 2 },
		{ 3, 4, 5 , 3, 4, 5, 3, 4, 5 },
		{ 6, 7, 8 , 6, 7, 8, 6, 7, 8 },
		{ 0, 1, 2 , 0, 1, 2, 0, 1, 2 },
		{ 3, 4, 5 , 3, 4, 5, 3, 4, 5 },
		{ 6, 7, 8 , 6, 7, 8, 6, 7, 8 },
		{ 0, 1, 2 , 0, 1, 2, 0, 1, 2 },
		{ 3, 4, 5 , 3, 4, 5, 3, 4, 5 },
		{ 6, 7, 8 , 6, 7, 8, 6, 7, 8 }
	};
	char S[N + 10][N + 10];

	void work()
	{
		int x, y, s, x1, y1, x2, y2, f = 0;
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j += M)
				scanf("%s", S[i] + j);
		scanf("%d%d", &x, &y);
		s = State[x - 1][y - 1];
		x1 = X1[s];
		y1 = Y1[s];
		x2 = X2[s];
		y2 = Y2[s];
		for(int i = x1; i <= x2; i++)
			for(int j = y1; j <= y2; j++)
				if(S[i][j] == '.')
				{
					S[i][j] = '!';
					f = 1;
				}
		if(!f)
			for(int i = 0; i < N; i++)
				for(int j = 0; j < N; j++)
					if(S[i][j] == '.')
						S[i][j] = '!';
		for(int i = 0; i < N; i += M)
		{
			for(int ii = 0; ii < M; ii++)
			{
				for(int j = 0; j < N; j += M)
				{
					for(int jj = 0; jj < M; jj++)
						putchar(S[i + ii][j + jj]);
					putchar(' ');
				}
				putchar('\n');
			}
			putchar('\n');
		}
	}
}

int main()
{
	program::work();
	return 0;
}