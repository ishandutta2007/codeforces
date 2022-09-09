#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

const int maxn = 2005;
const ll MOD = 1000000007LL;

ll a[maxn], b[maxn], cnk[maxn];
int n, k;

ll powmod(ll a, ll b)
{
    ll ans = 1;
    ll t = a;
    while (b != 0)
    {
        if ((b & 1) == 1)
        {
            ans = (ans * t) % MOD;
        }
        b >>= 1;
        t = (t * t) % MOD;
    }
    return ans;
}

ll divmod(ll a, ll b)
{
    ll c = powmod(b, MOD - 2);
    return (a * c) % MOD;
}

int main()
{
//     cerr << MOD << endl;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) scanf(LLD, &a[i]);
    if (k == 0)
    {
        for (int i = 0; i < n; i++) printf(LLD " ", a[i]);
        printf("\n");
        return 0;
    }
    k--;
    cnk[0] = 1;
    for (int i = 1; i < n; i++)
    {
        cnk[i] = divmod((cnk[i - 1] * (i + k)) % MOD, (ll)i);
//         cout << cnk[i] << endl;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++) b[i] = (b[i] + cnk[i - j] * a[j]) % MOD;
    }
    for (int i = 0; i < n; i++) printf(LLD " ", b[i]);
    printf("\n");
    return 0;
}