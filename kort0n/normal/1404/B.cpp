#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

const long long INF = 1e18;
//const ll mod = 1000000007;

vector<ll> edges[105000];
ll dist[3][105000];

void dfs(int idx, int now) {
    for(auto to : edges[now]) {
        if(chmin(dist[idx][to], dist[idx][now] + 1)) {
            dfs(idx, to);
        }
    }
}

void solve() {
    ll N, a, b, da, db;
    cin >> N >> a >> b >> da >> db;
    a--;
    b--;
    for(int i = 0; i < N; i++) {
        edges[i].clear();
        for(int j = 0; j < 3; j++) {
            dist[j][i] = INF;
        }
    }
    for(int i = 0; i < N - 1; i++) {
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dist[0][0] = 0;
    dfs(0, 0);
    ll P = 0;
    for(int i = 0; i < N; i++) {
        if(dist[0][i] > dist[0][P]) P = i;
    }
    dist[1][P] = 0;
    dfs(1, P);
    ll diameter = 0;
    for(int i = 0; i < N; i++) {
        chmax(diameter, dist[1][i]);
    }
    dist[2][a] = 0;
    dfs(2, a);
    bool ok = true;
    if(dist[2][b] <= da) ok = false;
    chmin(db, diameter);
    if(db <= 2 * da) ok = false;
    if(ok) cout << "Bob" << endl;
    else cout << "Alice" << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}