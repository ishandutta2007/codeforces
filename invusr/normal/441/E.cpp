#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef double r32;

const int MaxN = 200;
const int MaxM = MaxN + 32;
const int M = 255;

int x, n, p;
r32 f[MaxN + 1][M + 1][MaxM + 1][2];

inline void initialize()
{
	int up = x >> 8;
	int bit = up & 1, cnt = 0;
	while (up && (up & 1) == bit)
		up >>= 1, ++cnt;

	f[0][x & M][cnt][bit] = 1.0;
}

int main()
{
	cin >> x >> n >> p;
	r32 p1 = p * 0.01;
	r32 p2 = 1.00 - p1;

	initialize();

	for (int i = 0; i < n; ++i)
		for (int s = 0; s <= M; ++s)
			for (int j = 0; j < MaxM; ++j)
				for (int k = 0; k < 2; ++k)
				{
					r32 now = f[i][s][j][k];

					int bit = s >> 7 & 1;
					int cnt = bit == k ? j + 1 : 1;
					f[i + 1][s << 1 & M][cnt][bit] += now * p1;

					bit = s == M ? !k : k;
					cnt = s == M && !k ? 1 : j;
					f[i + 1][s + 1 & M][cnt][bit] += now * p2;
				}

	r32 res = 0.0;
	for (int s = 0; s <= M; ++s)
		for (int i = 0; i < MaxM; ++i)
			for (int j = 0; j < 2; ++j)
				res += f[n][s][i][j] * (s ? __builtin_ctz(s) : 8 + (j ? 0 : i));

	printf("%.8f\n", res);

	return 0;
}