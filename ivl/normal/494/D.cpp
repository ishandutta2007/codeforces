#include <cstdio>
#include <vector>
#define x first
#define y second

using namespace std;

const int M = 1000000007;
class mint{
      public:
      long long x;
      mint(int a){x = a % M;}
      mint(long long a){x = a % M;}
      mint(){x = 0;}
      mint operator+(mint a){
           a.x += x;
           if (a.x >= M) a.x -= M;
           return a;
      }
      mint operator-(mint a){
           a.x = x - a.x + M;
           if (a.x >= M) a.x -= M;
           return a;
      }
      mint operator*(mint a){
           a.x = (x * a.x) % M;
           return a;
      }
      void operator+=(mint a){*this = *this + a;}
      void operator-=(mint a){*this = *this - a;}
      void operator*=(mint a){*this = *this * a;}
};

int n;
vector < pair < int, mint > > veze[100005];
int par[100005]; mint pE[100005]; int dep[100005];
vector < pair < int, mint > > ch[100005];
void dfs_init(int pos, int par){
     ::par[pos] = par; if (pos != 1) dep[pos] = dep[par] + 1; // dep[root] = 0
     for (int i = 0; i < veze[pos].size(); ++i){
         if (veze[pos][i].x == par) continue;
         ch[pos].push_back(veze[pos][i]);
         dfs_init(veze[pos][i].x, pos);
     }
}
mint s0[100005], s1[100005], s2[100005];
void dfs_calc_s(int pos){
     s0[pos] = 1;
     s1[pos] = 0;
     s2[pos] = 0;
     for (int i = 0; i < ch[pos].size(); ++i){
         int nxt = ch[pos][i].x; mint E = ch[pos][i].y;
         pE[nxt] = E;
         dfs_calc_s(nxt);
         s0[pos] += s0[nxt];
         s1[pos] += s1[nxt] + s0[nxt] * E;
         s2[pos] += s2[nxt] + E * s1[nxt] * 2 + E * E * s0[nxt];
     }
}

int lca[100005][20]; mint lcaD[100005][20];
mint lca0[100005][20], lca1[100005][20], lca2[100005][20];

int raise(int pt, int amm){
    for (int i = 19; i >= 0; --i) if (amm & (1 << i)) pt = lca[pt][i];
    return pt;
}
mint raiseD(int pt, int amm){
     mint r;
     for (int i = 19; i >= 0; --i) if (amm & (1 << i)){
         r += lcaD[pt][i];
         pt = lca[pt][i];
     }
     return r;
}

mint d(int u, int v){
     if (dep[u] > dep[v]) swap(u, v);
     mint r;
     r += raiseD(v, dep[v] - dep[u]);
     v = raise(v, dep[v] - dep[u]); // ista razina
     for (int i = 19; i >= 0; --i) if (lca[u][i] != lca[v][i]){
         r += lcaD[u][i] + lcaD[v][i];
         u = lca[u][i];
         v = lca[v][i];
     }
     if (u != v) r += lcaD[u][0] + lcaD[v][0];
     return r;
}

mint h(int u, int v){ // suma{d(u, x)^2 : x E S(v)}
     if (dep[u] < dep[v] || raise(u, dep[u] - dep[v]) != v || u == v){ // u !E S(v)
        mint D = d(u, v);
        return s2[v] + D * s1[v] * 2 + D * D * s0[v];
     }
     // u E S(v); u != v
     mint r = s2[u];// printf("s2[%d] = %I64d\n", u, s2[u].x);
     int BIT = dep[u] - dep[v];// printf("BIT = %d\n", BIT);
     int P = u; // P je ono sto mijenjamo
     mint D = 0; // d(u, P)
     for (int i = 19; i >= 0; --i) if (BIT & (1 << i)){
         r += lca2[P][i] + D * lca1[P][i] * 2 + D * D * lca0[P][i];
         D += lcaD[P][i]; P = lca[P][i];
     }
     return r;
}

mint f(int u, int v){
     return h(u, v) * 2 - h(u, 1);
}

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i){
        int a, b; mint c;
        scanf("%d%d%I64d", &a, &b, &(c.x));
        veze[a].push_back(make_pair(b, c));
        veze[b].push_back(make_pair(a, c));
    }
    dfs_init(1, 1);
    dfs_calc_s(1);
    for (int i = 1; i <= n; ++i) lca[i][0] = par[i];
    for (int i = 1; i < 20; ++i) for (int j = 1; j <= n; ++j) lca[j][i] = lca[lca[j][i - 1]][i - 1];
    
    for (int i = 1; i <= n; ++i) lcaD[i][0] = pE[i];
    for (int i = 1; i < 20; ++i) for (int j = 1; j <= n; ++j) lcaD[j][i] = lcaD[j][i - 1] + lcaD[lca[j][i - 1]][i - 1];
    
    for (int i = 1; i <= n; ++i) lca0[i][0] = s0[par[i]] - s0[i];
    for (int i = 1; i < 20; ++i) for (int j = 1; j <= n; ++j) lca0[j][i] = lca0[j][i - 1] + lca0[lca[j][i - 1]][i - 1];
    
    for (int i = 1; i <= n; ++i) lca1[i][0] = s1[par[i]] - s1[i] - s0[i] * pE[i] + pE[i] * lca0[i][0];
    for (int i = 1; i < 20; ++i) for (int j = 1; j <= n; ++j) lca1[j][i] = lca1[j][i - 1] + lca1[lca[j][i - 1]][i - 1] + lcaD[j][i - 1] * lca0[lca[j][i - 1]][i - 1];
    
    for (int i = 1; i <= n; ++i) lca2[i][0] = s2[par[i]] - s2[i] - pE[i] * s1[i] * 2 - pE[i] * pE[i] * s0[i] + lca0[i][0] * pE[i] * pE[i] + pE[i] * (lca1[i][0] - pE[i] * lca0[i][0]) * 2;
    for (int i = 1; i < 20; ++i) for (int j = 1; j <= n; ++j) lca2[j][i] = lca2[j][i - 1] + lca2[lca[j][i - 1]][i - 1] + lcaD[j][i - 1] * lcaD[j][i - 1] * lca0[lca[j][i - 1]][i - 1] + lcaD[j][i - 1] * lca1[lca[j][i - 1]][i - 1] * 2;
    
    int q; scanf("%d", &q);
    for (int i = 0; i < q; ++i){
        int u, v; scanf("%d%d", &u, &v);
        printf("%I64d\n", f(u, v).x);
    }
    /*
    printf(" s2[] = %I64d\n", s2[1].x);
    printf(" s1[2] = %I64d\n", s1[2].x);
    printf("lca0 -> %I64d\n", lca0[2][0].x);
    printf("lca1 -> %I64d\n", lca1[2][0].x);
    printf("lca2 -> %I64d\n", lca2[2][0].x);
    while (true){
          int a, b; scanf("%d%d", &a, &b); printf("%I64d\n", h(a, b).x);
    }
    */
    return 0;
}