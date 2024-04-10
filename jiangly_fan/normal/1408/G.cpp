#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 1500 + 10;
constexpr int mod = 998244353;
int a[maxn][maxn];
struct Edge{
    int u, v, w;
};
int par[maxn << 1], p[maxn << 1];
vector<int> son[maxn << 1];
int parent[maxn << 1];
int gp(int u){
    return p[u] < 0 ? u : p[u] = gp(p[u]);
}
vector<int> nxt[maxn];
int dfn, L[maxn << 1], R[maxn << 1];
void DFS(int u){
    if(son[u].empty()){
        dfn += 1;
        L[u] = R[u] = dfn;
        //cout << u << "\n";
    }
    else{
        L[u] = maxn;
        for(int v : son[u]){
            DFS(v);
            L[u] = min(L[u], L[v]);
            R[u] = max(R[u], R[v]);
        }
    }
}
int dp[maxn][maxn];
void add(int& x, int y){
    x += y;
    if(x >= mod) x -= mod;
}
int minp[maxn][maxn], mins[maxn][maxn], b[maxn][maxn];
int maxp[maxn][maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 0; i < n; i += 1){
        p[i] = -1;
        for(int j = 0; j < n; j += 1)
            cin >> a[i][j];
    }
    vector<Edge> edges;
    for(int i = 0; i < n; i += 1)
        for(int j = 0; j < i; j += 1)
            edges.push_back({i, j, a[i][j]}); 
    sort(edges.begin(), edges.end(), [](const Edge& x, const Edge& y){
        return x.w < y.w;
    });
    int r = n;
    for(auto e : edges){
        int pu = gp(e.u), pv = gp(e.v);
        if(pu == pv) continue;
        else{
            //cout << pu << " " << pv << " " << r << "\n";
            par[pu] = r;
            par[pv] = r;
            son[r].push_back(pu);
            son[r].push_back(pv);
            p[pu] = r;
            p[pv] = r;
            p[r] = -1;
            r += 1;
        }
    }
    DFS(r - 1);
    for(int i = 0; i < n; i += 1)
        for(int j = 0; j < n; j += 1)
            b[L[i]][L[j]] = a[i][j];
    for(int i = 1; i <= n; i += 1)
        for(int j = 1; j <= n; j += 1)
            minp[i][j] = j == 1 ? b[i][j] : min(b[i][j], minp[i][j - 1]);
    for(int i = 1; i <= n; i += 1)
        for(int j = n; j >= 1; j -= 1)
            mins[i][j] = j == n ? b[i][j] : min(b[i][j], mins[i][j + 1]);
    for(int i = 1; i <= n; i += 1)
        for(int j = i; j <= n; j += 1)
            maxp[i][j] = j == i ? 0 : max(b[i][j], maxp[i][j - 1]);

    for(int i = 0; i < r; i += 1){
        int x = L[i], y = R[i];
        int ma = 0, mi = INT_MAX;
        for(int j = x; j <= y; j += 1){
            if(x > 1) mi = min(minp[j][x - 1], mi);
            if(y < n) mi = min(mins[j][y + 1], mi);
            ma = max(maxp[j][y], ma);
        }
        //cout << x << " " << y << " " << mi << " " << ma << "\n";
        if(ma < mi) nxt[x - 1].push_back(y);
    }
    dp[0][0] = 1;
    for(int i = 0; i < n; i += 1)
        for(int j = 0; j < n; j += 1)
            for(int k : nxt[i])
                add(dp[k][j + 1], dp[i][j]);
    for(int i = 1; i <= n; i += 1)
        cout << dp[n][i] << " ";
    return 0;
}