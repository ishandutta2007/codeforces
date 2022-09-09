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

const int maxn = 1000006;

int a[maxn];
int n;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	ll curmaxlR = -a[0];
	ll curmaxLr = a[0];
	for (int i = 0; i < n; i++)
	{
		ll curd = max(a[i] + curmaxlR, -a[i] + curmaxLr);
		if (i + 1 == n) cout << curd << endl;
		else
		{
			curmaxlR = max(curmaxlR, curd - a[i + 1]);
			curmaxLr = max(curmaxLr, curd + a[i + 1]);
		}
	}
	return 0;
}