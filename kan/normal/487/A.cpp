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

inline int f(int h, int a, int d)
{
	if (a <= d) return 1e9;
	return (h + (a - d) - 1) / (a - d);
}

int main()
{
	int h_y, h_m, a_y, a_m, d_y, d_m;
	int h, a, d;
	cin >> h_y >> a_y >> d_y;
	cin >> h_m >> a_m >> d_m;
	cin >> h >> a >> d;
	int answer = 1e9;
	for (int i = 0; i <= 3000; i++) // h
	{
		for (int j = 0; j <= 200; j++) // a
		{
			for (int k = 0; k <= 100; k++) // d
			{
				if (f(h_m, a_y + j, d_m) < f(h_y + i, a_m, d_y + k))
				{
					answer = min(answer, i * h + j * a + k * d);
				}
			}
		}
	}
	assert(answer < 1e9 - 1);
	cout << answer << endl;
	return 0;
}