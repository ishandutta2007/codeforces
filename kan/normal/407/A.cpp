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

int main()
{
	int a, b;
	cin >> a >> b;
	for (int xa = 1; xa < a; xa++)
	{
		int ya = sqrt(a * a - xa * xa) + 0.1;
		if (ya * ya + xa * xa != a * a) continue;
		for (int xb = 1; xb < b; xb++)
		{
			int yb = sqrt(b * b - xb * xb) + 0.1;
			if (yb * yb + xb * xb != b * b) continue;
			if (ya == yb) continue;
			if (xa * (-xb) + ya * yb != 0) continue;
			printf("YES\n0 0\n%d %d\n%d %d\n", xa, ya, -xb, yb);
			exit(0);
		}
	}
	printf("NO\n");
	return 0;
}