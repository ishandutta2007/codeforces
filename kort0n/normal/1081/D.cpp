#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
bool special[100050];
struct UnionFind {
    vector<int> par;
    vector<int> rank;
    vector<ll> size;
    UnionFind(int n = 1) {
        init(n);
    }

    void init(int n = 1) {
        par.resize(n + 1); rank.resize(n + 1); size.resize(n + 1);
        for (int i = 0; i <= n; ++i) {
            par[i] = i, rank[i] = 0;
            size[i] = 0;
            if(special[i]) size[i] = 1;
        }
    }

    int root(int x) {
        if (par[x] == x) {
            return x;
        }
        else {
            return root(par[x]);
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
        size[x] += size[y];
        return true;
    }

    ll Size(int x){
        return size[root(x)];
    }
};


int main() {
    //cout.precision(10);
    for(int i = 0; i <= 100000; i++){
        special[i] = false;
    }
    int n, m, k;
    cin >> n >> m >> k;
    int checker;
    for(int i = 1; i <= k; i++){
        int x;
        cin >> x;
        checker = x;
        special[x] = true;
    }
    UnionFind uni(100050);
    vector<pair<ll, pair<int, int> > > vec;
    for(int i = 1; i <= m; i++){
        int u, v;
        ll w;
        cin >> u >> v >> w;
        vec.push_back({w, {u, v}});
    }
    sort(vec.begin(), vec.end());
    for(int i = 0; i < vec.size(); i++){
        int u = vec[i].second.first;
        int v = vec[i].second.second;
        ll cost = vec[i].first;
        uni.merge(u, v);
        //cout << cost << uni.Size(checker) << endl;
        if(uni.Size(checker) == k){
            for(int j = 0; j < k; j++){
                cout << cost;
                if(j < k - 1) cout << " ";
            }
            cout << endl;
            return 0;
        }
    }
    return 0;
}