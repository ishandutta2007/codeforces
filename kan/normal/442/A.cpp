#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cassert>
#include <ctime>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

const char lett[6] = "RGBYW";

char s[5];
int kvx[10], kvy[10];
bool was[5][5];
int n;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", s);
		int y = s[1] - '1';
		for (int x = 0; x < 5; x++) if (lett[x] == s[0]) was[x][y] = true;
	}
	int answer = 10;
	for (int maskx = 0; maskx < (1 << 5); maskx++)
	{
		for (int masky = 0; masky < (1 << 5); masky++)
		{
			for (int i = 0; i < 5; i++) kvx[i] = 0;
			for (int i = 0; i < 5; i++) kvy[i] = 0;
			int kv0 = 0;
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++) if (was[i][j])
				{
					if (maskx & (1 << i))
					{
						if (!(masky & (1 << j))) kvx[i]++;
					} else
					{
						if (masky & (1 << j)) kvy[j]++;
						else kv0++;
					}
				}
			}
			bool ok = true;
			ok &= *max_element(kvx, kvx + 5) <= 1;
			ok &= *max_element(kvy, kvy + 5) <= 1;
			ok &= kv0 <= 1;
			if (ok) answer = min(answer, __builtin_popcount(maskx) + __builtin_popcount(masky));
		}
	}
	cout << answer << endl;
	return 0;
}