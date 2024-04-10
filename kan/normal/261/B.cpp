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

const int maxn = 105;

ld fact[maxn];
ld kv[maxn][maxn];
int a[maxn];
int n, p;

int main()
{
    scanf("%d", &n);
    int sum = 0;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]), sum += a[i];
    scanf("%d", &p);
    if (sum <= p)
    {
        cout << n << endl;
        return 0;
    }
    ld ans = 0;
    fact[0] = 1;
    for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i;
    for (int i = 0; i < n; i++)
    {
        memset(kv, 0, sizeof kv);
        kv[0][0] = 1;
        for (int j = 0; j < n; j++) if (j != i)
        {
            for (int k = n; k >= 0; k--)
            {
                for (int t = 0; t <= p; t++) kv[k + 1][t + a[j]] += kv[k][t];
            }
        }
        for (int k = 0; k <= n; k++)
        {
            for (int t = p; t > max(p - a[i], 0); t--) ans += k * kv[k][t] * fact[k] * fact[n - k - 1] / fact[n];
        }
    }
    cout.precision(20);
    cout << ans << endl;
	return 0;
}