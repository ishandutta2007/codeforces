#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define G(x) ll x; cin >> x;
#define GS(s) string s; cin >> s;
#define F(i, l, r) for(ll i = l; i < r; i++)
#define M 998244353
#define N 500010
#define ADD(i1, i2) ans = ans * r(i2 - i1 - 1, s[i2] - '0') % M, nonOnes.insert(i2);
#define REM(i1, i2) ans = ans * inv(r(i2 - i1 - 1, s[i2] - '0'), M) % M, nonOnes.erase(i2);

set<ll> nonOnes;
ll dp[N][10], ans;

ll inv(ll a, ll b) { return 1 < a ? b - inv(b % a, a) * b / a : 1; }

ll r(ll i, ll dig) {
    if(i < 0) return 1;
    if(~dp[i][dig]) return dp[i][dig];
    if(i == 0) return dig + 1;
    return dp[i][dig] = ((9 - dig) * r(i - 2, 1) + (dig + 1) * r(i - 1, 1)) % M;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof dp);
    G(n) G(m) GS(s) s += "9";
    ans = inv(10, M);
    nonOnes.insert(-1);
    F(i, 0, n + 1) if(s[i] - '1') ADD(*nonOnes.rbegin(), i)
    while(m--) {
        G(x) G(d) x--;
        ll lower = *(--nonOnes.lower_bound(x));
        ll upper = *nonOnes.upper_bound(x);
        if(d != s[x] - '0') {
            if(d == 1) {
                REM(lower, x)
                REM(x, upper)
                s[x] = '1';
                ADD(lower, upper) 
            } else if(s[x] - '1') {
                REM(lower, x)
                s[x] = d + '0';
                ADD(lower, x)
            } else {
                REM(lower, upper)
                s[x] = d + '0';
                ADD(lower, x)
                ADD(x, upper)
            }
        }
        cout << ans << '\n';
    }
}