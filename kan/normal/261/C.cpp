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

// int a[100][100];
const int maxt = 63;

ll kv[100][100];
ll n, t;
ll answer;

ll get(ll t, ll x, ll sz)
{
//     cout << "get " << t << ' ' << x << ' ' << sz << endl;
    if (t < 0) return 0;
    if (sz == -1)
    {
        if (t == 0) return 1;
        else return 0;
    }
    if (x < (1LL << sz)) return get(t, x, sz - 1);
    else
    {
        ll ans = get(t - 1, x - (1LL << sz), sz - 1) + kv[sz][t];
//         cout << "return " << ans << endl;
        return ans;
    }
}

int main()
{
    cin >> n >> t;
/*    memset(a, 0, sizeof(a));
    a[0][n] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (j == 0) a[i][j] = a[i - 1][j + 1];
            else if (j == n) a[i][j] = a[i - 1][j - 1];
            else a[i][j] = (a[i - 1][j - 1] ^ a[i - 1][j + 1]);
        }
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++) cout << (a[i][j] ? "#" : ".");
        cout << endl;
    }*/
    int wht = -1;
    for (int i = 0; (1LL << i) <= t; i++)
    {
        if ((1LL << i) == t) wht = i;
    }
    if (wht == -1)
    {
        cout << 0 << endl;
        return 0;
    }
    kv[0][0] = 1;
    int cur = 0;
    ll curkv = 1;
    for (; curkv < n + 1; cur++)
    {
        curkv += (1LL << (cur + 1));
        answer += kv[cur][wht];
        for (int i = maxt; i >= 1; i--) kv[cur + 1][i] = kv[cur][i - 1] + kv[cur][i];
        kv[cur + 1][0] = kv[cur][0];
    }
//     cout << answer << endl;
    curkv -= (1LL << cur);
    cur--;
//     cout << n << ' ' << curkv << endl;
    answer += get(wht, n - curkv, cur);
//     cout << answer << endl;
    cout << answer - (t == 1LL) << endl;
	return 0;
}