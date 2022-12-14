#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

const int MaxN = 120;
const int N = 15000;
const int M = 5;

int n, tick[MaxN][M];
int solved[M];

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < M; ++j)
		{
			cin >> tick[i][j];
			if (~tick[i][j])
				++solved[j];
		}

	for (int i = 0; i <= n * 31; ++i)
	{
		int total = n + i;
		int score0 = 0, score1 = 0;
		for (int j = 0; j < M; ++j)
		{
			int now = solved[j];
			if (~tick[1][j] && tick[0][j] > tick[1][j])
				now += i;

			int value = 500;
			while (value < 3000 && 2 * now <= total)
				now *= 2, value += 500;
			if (~tick[0][j])
				score0 += value / 250 * (250 - tick[0][j]);
			if (~tick[1][j])
				score1 += value / 250 * (250 - tick[1][j]);
		}

		if (score0 > score1)
		{
			cout << i << endl;
			return 0;
		}
	}

	cout << -1 << endl;

	return 0;
}