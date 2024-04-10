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

const int maxn = 200005;
const int MAX = 1000006;

int a[maxn];
int n;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
// 	n = 200000;
// 	for (int i = 0; i < n; i++) a[i] = rand() % 1000000 + 1;
// 	auto start = clock();
	sort(a, a + n);
	n = unique(a, a + n) - a;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 2 * a[i]; j < MAX; j += a[i])
		{
			ans = max(ans, *(lower_bound(a, a + n, j) - 1) % a[i]);
		}
		ans = max(ans, a[n - 1] % a[i]);
	}
	cout << ans << endl;
// 	cerr << (double)(clock() - start) / CLOCKS_PER_SEC << endl;
	return 0;
}