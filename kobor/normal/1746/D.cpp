#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, b, e) for(int i = (b); i < (e); i++)
#define TRAV(x, a) for(auto &x: a)
#define SZ(x) ((int)x.size())
using K = long double;
using vi = vector<int>;
using ii = pair<int, int>;
using ll = long long;
#define X first
#define Y second
#define PB push_back
constexpr int INF = 0x3f3f3f3f;

vi score;
vector<vi> G;

pair<ll, int> dfs(int v, int k) {
    ll ans = 1ll * k * score[v];
    if(SZ(G[v]) == 0) return {ans, score[v]};
    vi syny;
    int ile = k / SZ(G[v]);
    TRAV(x, G[v]) {
        auto ret = dfs(x, ile);
        ans += ret.X;
        syny.PB(ret.Y);
    }
    sort(syny.begin(), syny.end(), greater<int>());
    FOR(i, 0, k % SZ(G[v])) ans += syny[i];
    return {ans, syny[k % SZ(G[v])] + score[v]};
}

void solve() {
    int n, k;
    cin >> n >> k;
    G = vector<vi>(n);
    FOR(i, 1, n) {
        int a;
        cin >> a;
        G[a - 1].PB(i);
    }
    score = vi(n);
    TRAV(x, score) cin >> x;
    cout << dfs(0, k).X << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    FOR(te, 0, tt) solve();
    // solve();
    return 0;
}