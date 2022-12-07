#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1005;
const int M = N * N;
int n, m, q;

struct Edge {
    int u, v, w, id;
    void read(int id) {
        scanf("%d%d%d", &u, &v, &w);
        u--; v--;
        this->id = id;
    }
    bool operator < (const Edge& c) const {
        return w > c.w;
    }
} e[M];

int parent[N * 2];

int find(int x){
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

int gao(int l, int r) {
    for (int i = 0; i < n * 2; i++) parent[i] = i;
    for (int i = 1; i <= m; i++) {
        if (e[i].id < l || e[i].id > r) continue;
        int pu = find(e[i].u * 2), pv = find(e[i].v * 2 + 1);
        if (pu != pv) {
            parent[pu] = pv;
            parent[find(e[i].u * 2 + 1)] = find(e[i].v * 2);
        }
        if (find(e[i].u * 2) == find(e[i].u * 2 + 1)) return e[i].w;
        if (find(e[i].v * 2) == find(e[i].v * 2 + 1)) return e[i].w;
    }
    return -1;
}

int main() {
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= m; i++)
        e[i].read(i);
    sort(e + 1, e + 1 + m);
    int l, r;
    while (q--) {
        scanf("%d%d", &l, &r);
        printf("%d\n", gao(l, r));
    }
    return 0;
}