#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;
struct Edge{
    int src, dst, cost;
    bool operator < (const Edge& e) const {
        return cost < e.cost;
    }
};

struct UnionFind {
    vector<int> data;
    UnionFind(int N) : data(N, -1) { }
    // xy
    bool unite(int x, int y) {
        x = root(x); y = root(y);
        if (x != y) {
            if (data[x] > data[y]) swap(x, y);
            data[x] += data[y]; data[y] = x;
        }
        return x != y;
    }
    // xy
    bool same(int x, int y) {
        return root(x) == root(y);
    }
    // x
    int size(int x) {
        return -data[root(x)];
    }
    int root(int x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }
};

typedef vector<Edge> Node;
typedef vector<Node> Graph;

int n;
bool solve() {
    static int d[2001][2001] = {};
    vector<Edge> es;
    bool ans = true;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int cost;
            scanf("%d", &cost);
            if(i == j && cost > 0) ans = false;
            if(i != j && cost == 0) ans = false;
            if(i > j && cost != d[j][i]) ans = false;
            d[i][j] = cost;
            if(i < j) es.push_back({i, j, cost});
        }
    }

    if(!ans) return false;

    sort(es.begin(), es.end());
    UnionFind uf(n);
    Graph G(n);
    for(int i = 0; i < es.size(); i++) {
        bool b = uf.unite(es[i].src, es[i].dst);
        if(b) {
            G[es[i].src].push_back({es[i].src, es[i].dst, es[i].cost});
            G[es[i].dst].push_back({es[i].dst, es[i].src, es[i].cost});
        }
    }

    int dist[2001];
    REP(s, n) {
        REP(g, n) dist[g] = INT_MAX;
        dist[s] = 0;
        queue<int> que;
        que.push(s);
        while(!que.empty()) {
            int a = que.front(); que.pop();
            for(const Edge& e : G[a]) {
                int b = e.dst;
                if(dist[b] > dist[a] + e.cost) {
                    dist[b] = dist[a] + e.cost;
                    que.push(b);
                }
            }
        }
        REP(g, n) if(dist[g] != d[s][g]) return false;
    }

    return true;
}


int main(){
    while(cin >> n){
        bool ans = solve();
        cout << (ans ? "YES" : "NO") << endl;
    }
    return 0;
}