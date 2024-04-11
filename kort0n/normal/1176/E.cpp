#include <bits/stdc++.h>
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

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
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

vector<int> pathes[205000];
int color[205000];

void dfs(int now, int c, int from) {
    color[now] = c;
    for(int i = 0; i < pathes[now].size(); i++) {
        int to = pathes[now][i];
        if(to == from) continue;
        dfs(to, 1 - c, now);
    }
}

void solve() {
    ll n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) pathes[i].clear();
    UnionFind uni(n + 1);
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        if(uni.merge(u, v)) {
            pathes[u].push_back(v);
            pathes[v].push_back(u);
        }
    }
    dfs(1, 0, -1);
    int num = 0;
    int checker = 0;
    for(int i = 1; i <= n; i++) {
        if(color[i] == 0) num++;
    }
    if(num > n / 2) {
        checker = 1;
        num = n - num;
    }
    cout << num << endl;
    for(int i = 1; i <= n; i++) {
        //cerr << i << " " << color[i] << endl;
        if(color[i] == checker) cout << i << " ";
    }
    cout << endl;
}


int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}