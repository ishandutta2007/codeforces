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
    int n, k;
    cin >> n >> k;
    int a, maks = 0;
    FOR(i, 0, n) {
        cin >> a;
        maks = max(maks, a);
    }
    cout << (maks > 0 ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    FOR(te, 0, tt) solve();
    // solve();
    return 0;
}