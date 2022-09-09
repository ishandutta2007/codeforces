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

const int maxn = 2005;
const int inf = 1e9;

int a[maxn], ans[maxn];
int n, k;

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	sort(a, a + n);
	ans[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		ans[i] = inf;
		for (int j = 1; j <= k && i - j >= 0; j++) ans[i] = min(ans[i], ans[i - j] + 2 * (a[i - 1] - 1));
	}
	cout << ans[n] << endl;
	return 0;
}