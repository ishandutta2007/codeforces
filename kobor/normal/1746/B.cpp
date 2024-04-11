#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, b, e) for(int i = (b); i < (e); i++)
#define TRAV(x, a) for(auto &x: a)
#define SZ(x) ((int)x.size())
using K = long double;
using vi = vector<int>;
using ii = pair<int, int>;
#define X first
#define Y second
#define PB push_back
constexpr int INF = 0x3f3f3f3f;


void solve() {
    int n;
    cin >> n;
    deque<int> q(n);
    TRAV(x, q) cin >> x;
    int ans = 0;
    while(SZ(q)) {
        if(q[0] == 0) q.pop_front();
        else if(q.back() == 1) q.pop_back();
        else ans++, q.pop_front(), q.pop_back();
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    FOR(te, 0, tt) solve();
    // solve();
    return 0;
}