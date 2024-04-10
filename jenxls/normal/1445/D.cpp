#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <sstream>
#include <numeric>
#include <cstdio>
#include <bitset>

#define int ll 

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;


#define pb push_back
#define F first
#define S second
#define _sz(x) ((int)x.size())

const int N = 4e5 + 20, mod = 998244353;
int n;
int a[N];

int fac[N], ifac[N];

inline int pw (int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = 1ll * res * a % mod;
        a = 1ll * a * a % mod;
        b /= 2;
    }

    return res;
}

inline int C (int n, int k) {
    if (k > n || k < 0) return 0;
    return 1ll * fac[n] * ifac[k] % mod * ifac[n - k] % mod;
}

int32_t main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    for (int i = fac[0] = ifac[0] = 1; i < N; i++) {
        fac[i] = 1ll * fac[i - 1] * i % mod;
        ifac[i] = pw(fac[i], mod - 2);
    }
    
    cin >> n;

    for (int i = 0; i < 2 * n; i++) cin >> a[i];

    sort(a, a + 2 * n);

    int ans = 0;

    for (int i = 1; i < 2 * n; i++)
        ans = (ans + 1ll * min(i, 2 * n - i) * (a[i] - a[i - 1])) % mod;

    ans = 1ll * ans * C(2 * n, n) % mod;

    cout << ans << '\n';
}