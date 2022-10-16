#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
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

struct path {
    int v;
    int u;
    int cost;
};

bool comp(path p1, path p2) {
    return p1.cost < p2.cost;
}

int main() {
    //cout.precision(10);
    UnionFind uni(200010);
    int n, m;
    cin >> n >> m;
    vector<path> pathes(m + 1);
    for(int i = 0; i < m; i++) {
        cin >> pathes[i].u >> pathes[i].v >> pathes[i].cost;
    }
    pathes[m] = {1, 1, 2000000000};
    sort(pathes.begin(), pathes.end(), comp);
    int before = 0;
    int after = 0;
    int ans = 0;
    while(uni.size(1) < n) {
        while(pathes[before].cost == pathes[after + 1].cost) after++;
        for(int i = before; i <= after; i++) {
            path now = pathes[i];
            if(uni.issame(now.u, now.v)) pathes[i].cost = -1;
        }
        for(int i = before; i <= after; i++) {
            if(pathes[i].cost == -1) continue;
            path now = pathes[i];
            if(!uni.merge(now.u, now.v)) ans++;
        }
        before = after + 1;
        after = before;
    } 
    cout << ans << endl;
    //cout << pathes[0].cost << endl;
    return 0;
}