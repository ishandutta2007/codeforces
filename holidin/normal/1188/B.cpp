#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
const int N = 2e5 + 1;
int mod;

map <int, int> m;

int bp(ll x, int st) {
    if (st == 0)
        return 1;
    else if (st % 2 == 0)
            return bp((x * x) % mod, st / 2);
        else
            return (bp((x * x) % mod, st / 2) * x) % mod;
}

int main() {
    int i, j, k, n;
    long long x;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> mod >> k;
    long long ans = 0;
    for (i = 1; i <= n; ++i) {
        cin >> x;
        ans += m[(bp(x, 4) - (k * x) % mod + mod) % mod];
        ++m[(bp(x, 4) - (k * x) % mod + mod) % mod];
    }
    cout << ans;
}