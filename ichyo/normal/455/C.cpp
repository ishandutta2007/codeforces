#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

typedef pair<int, int> Result;
typedef vector<int> Node;
typedef vector<Node> Graph;
Result visit(int p, int v, const Graph &g) {
  Result r(0, v);
  for(int u : g[v]) if (u != p) {
    Result t = visit(v, u, g);
    t.first += 1;
    if (r.first < t.first) r = t;
  }
  return r;
}
int diameter(const Graph &g, int s) {
  Result r = visit(-1, s, g);
  Result t = visit(-1, r.second, g);
  return t.first; // (r.second, t.second) is farthest pair
}

struct UnionFind {
    vector<int> data;
    vector<int> rad; // radius
    vector<int> dia; // diameter
    UnionFind(int N) : data(N, -1), rad(N, -1), dia(N, -1) { }
    // xy
    bool unite(int x, int y) {
        x = root(x); y = root(y);
        if (x != y) {
            if (data[x] > data[y]) swap(x, y);
            data[x] += data[y]; data[y] = x;
        }
        return x != y;
    }
    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if(x == y) return false;
        int R1 = dia[x];
        int R2 = dia[y];
        // assert(R1 != -1);
        // assert(R2 != -1);
        int r1 = rad[x];
        int r2 = rad[y];
        // assert(r1 != -1);
        // assert(r2 != -1);
        int R = max(max(R1, R2), r1 + r2 + 1);
        int r = min( max(r1, r2 + 1), max(r2, r1 + 1) );
        // assert((R + 1) / 2 == r);
        // printf("r1 = %d\n", r1);
        // printf("r2 = %d\n", r2);
        // printf("R1 = %d\n", R1);
        // printf("R2 = %d\n", R2);
        // printf("R = %d\n", R);
        // printf("r = %d\n", r);

        // merge
        if (data[x] > data[y]) swap(x, y);
        data[x] += data[y]; data[y] = x;

        dia[x] = R;
        rad[x] = r;
        dia[y] = -1; // no need
        rad[y] = -1; // no need
        return true;
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

int main(){
    int n, m, q;
    while(cin >> n >> m >> q) {
        Graph G(n);
        UnionFind uf(n);
        REP(i, m) {
            int a, b;
            scanf("%d %d", &a, &b);
            a--; b--;
            G[a].push_back(b);
            G[b].push_back(a);
            uf.unite(a, b);
        }
        REP(i, n) if(uf.root(i) == i) {
            uf.dia[i] = diameter(G, i);
            uf.rad[i] = (uf.dia[i] + 1) / 2;
        }
        REP(i, q) {
            int type;
            scanf("%d", &type);
            if(type == 1) {
                int x;
                scanf("%d", &x);
                x--;
                int res = uf.dia[ uf.root(x) ];
                // assert(res != -1);
                printf("%d\n", res);
            } else {
                int x, y;
                scanf("%d %d", &x, &y);
                x--; y--;
                uf.merge(x, y);
            }
        }
    }
    return 0;
}