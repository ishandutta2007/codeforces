#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, b, e) for(int i = (b); i < (e); i++)
#define TRAV(x, a) for(auto &x: a)
#define PB push_back
#define SZ(x) ((int)x.size())
#define X first
#define Y second
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
constexpr int INF = 0x3f3f3f3f;

ll last(ll n, int k) {
    ll l = 0, r = INF, mid;
    while(l + 1 < r) {
        mid = (l + r) / 2;
        if(mid * (mid + k) <= n) l = mid;
        else r = mid;
    }
    return l;
}

ll f(ll n) {
    if(n == 0) return 0;
    return last(n, 0) + last(n, 1) + last(n, 2);
}

void solve() {
    ll l, r;
    cin >> l >> r;
    cout << f(r) - f(l - 1) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    FOR(te, 0, tt) solve();
    // solve();
    return 0;
}