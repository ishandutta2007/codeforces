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

#define pb push_back
#define all(x) begin(x), end(x)

const int maxn = 1000006;

int z[maxn];
char s[maxn];
int add[maxn];
int n, k;

int main()
{
	scanf("%d%d", &n, &k);
	scanf("%s", s);
	int l = 0;
	int r = 0;
	for (int i = 1; i < n; i++)
	{
		z[i] = max(0, min(r - i, z[i - l]));
		while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
		if (i + z[i] > r)
		{
			r = i + z[i];
			l = i;
		}
	}
	for (int len = 1; len * k <= n; len++) if (z[len] >= len * (k - 1))
	{
		add[len * k - 1]++;
		add[min(len * (k + 1), len * k + z[len * k])]--;
	}
	int b = 0;
	for (int i = 0; i < n; i++)
	{
		b += add[i];
		if (b > 0) printf("1");
		else printf("0");
	}
	return 0;
}