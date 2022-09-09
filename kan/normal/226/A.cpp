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

const int maxn = 40;

ll ansk[maxn], ansa[maxn], ans[maxn];
int n;
ll MOD;

int powmod(int x)
{
    ll ans = 0;
    int cur = 1;
    while (x)
    {
        if (x & 1) ans += (ansk[cur] * ans + ansa[cur]) % MOD;
        ans = ans % MOD;
        cur++;
        x >>= 1;
    }
    return ans;
}

int main()
{
    scanf("%d" LLD, &n, &MOD);
    ansk[1] = 2;
    ansa[1] = 2;
    ans[1] = 2;
    for (int i = 2; i < 32; i++) 
    {
        ansk[i] = (ansk[i - 1] * ansk[i - 1] + 2 * ansk[i - 1]) % MOD;
        ansa[i] = (ansa[i - 1] * 2 + ansk[i - 1] * ansa[i - 1]) % MOD;
//         ans[i] = (ansk[i] * ans[i - 1] + ansa[i]) % MOD;
//         cerr << ' ' << ansk[i] << ' ' << ansa[i] << ' ' << i << endl;
    }
    printf("%d\n", powmod(n));
	return 0;
}