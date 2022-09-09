#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

const int maxn = 100005;

ll a[maxn];
bool can[maxn];
int n, k;

int main()
{
    scanf("%d%d", &n, &k);
    if (k == 1)
    {
        printf("%d\n", n);
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        a[i] = x;
    }
    sort(a, a + n);
    a[n] = a[n - 1] * k + 2;
    for (int i = 0; i < n; i++) can[i] = true;
    int cur = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        while (a[cur] < a[i] * k) cur++;
        if (can[i]) ans++;
        if (can[i] && a[cur] == a[i] * k) can[cur] = false;
    }
    printf("%d\n", ans);
	return 0;
}