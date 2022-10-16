#include <bits/stdc++.h>
//#include <atcoder/all>
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
struct UnionFind {
    vector<int> par;
    vector<int> rank;
    vector<ll> Size;
    UnionFind(int n = 1) {
        init(n);
    }

    void init(int n = 1) {
        par.resize(n + 1); rank.resize(n + 1); Size.resize(n + 1);
        for (int i = 0; i <= n; ++i) par[i] = i, rank[i] = 0, Size[i] = 1;
    }

    int root(int x) {
        if (par[x] == x) {
            return x;
        }
        else {
            int r = root(par[x]);
            return par[x] = r;
        }
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y);
        if (rank[x] == rank[y]) ++rank[x];
        par[y] = x;
        Size[x] += Size[y];
        return true;
    }

    ll size(int x){
        return Size[root(x)];
    }
};

vector<ll> edges[301000];
bool BAN[310000];
ll dist[310000];

void solve() {
    ll N, M;
    cin >> N >> M;
    UnionFind uni(N);
    for(int i = 0; i < N; i++) {
        edges[i].clear();
        BAN[i] = false;
        dist[i] = INF;
    }
    for(int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
        uni.merge(u, v);
    }
    if(uni.size(0) != N) {
        cout <<"NO" << endl;
        return;
    }
    cout << "YES" << endl;
    vector<ll> ans;
    queue<ll> que;
    dist[0] = 0;
    que.push(0);
    while(que.size()) {
        auto from = que.front();
        que.pop();
        for(auto to : edges[from]) {
            if(chmin(dist[to], dist[from] + 1)) que.push(to);
        }
    }
    vector<ll> a(N);
    for(int i = 0; i < N; i++) a[i] = i;
    sort(a.begin(), a.end(), [&](int c, int d){
        return dist[c] < dist[d];
    });
    for(auto tmp : a) {
        if(BAN[tmp]) continue;
        ans.push_back(tmp);
        for(auto to : edges[tmp]) BAN[to] = true;
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++) {
        if(i != 0) cout << " ";
        cout << ans[i] + 1;
    }
    cout << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}