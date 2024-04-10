#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector < int > V[100005];

int lca[100005][20];
int dep[100005];
int size[100005];
int rootaj(int pos, int par){
    if (dep[pos]) return 0;
    lca[pos][0] = par;
    dep[pos] = dep[par] + 1;
    int &sz = size[pos];
    sz = 1;
    for (int i = 0; i < V[pos].size(); ++i)
        sz += rootaj(V[pos][i], pos);
    return sz;
}

int lift(int a, int v){for (int i = 0; i < 20; ++i) if ((v >> i) & 1) a = lca[a][i]; return a;}
int dist(int a, int b){
    if (dep[a] < dep[b]) swap(a, b);
    int len = 0;
    len += dep[a] - dep[b];
    a = lift(a, len);
    if (a == b) return len;
    len += 2;
    for (int i = 19; i >= 0; --i)
        if (lca[a][i] != lca[b][i]) a = lca[a][i], b = lca[b][i], len += 2 * (1 << i);
    return len;
}

int calc(int a, int b){
    if (a == b) return size[1];
    if (dep[a] < dep[b]) swap(a, b);
    if ((dep[a] ^ dep[b]) & 1) return 0;
    int aa = a, bb = b;
    int x = dist(aa, bb) / 2;
    int R = 0;
    if (dep[a] != dep[b]){
       aa = lift(a, x - 1);
       R -= size[aa];
       aa = lca[aa][0];
       R += size[aa];
    }
    else {
         R = size[1];
         aa = lift(a, x - 1);
         bb = lift(b, x - 1);
         R -= size[aa];
         R -= size[bb];
    }
    return R;
}

int main(){
    scanf("%d", &n);
    for (int i = 1; i < n; ++i){
        int a, b;
        scanf("%d%d", &a, &b);
        V[a].push_back(b);
        V[b].push_back(a);
    }
    rootaj(1, 1);
    for (int t = 1; t < 20; ++t)
        for (int i = 0; i <= n; ++i)
            lca[i][t] = lca[lca[i][t - 1]][t - 1];
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; ++i){
        int a, b;
        scanf("%d%d", &a, &b);
        int c = calc(a, b);
        printf("%d\n", c);
    }
    return 0;
}