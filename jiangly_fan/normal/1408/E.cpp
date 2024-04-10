#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 200000 + 1;
int p[maxn], a[maxn], b[maxn];
struct Edge{
    int u, v, w;
};
int gp(int u){
    return p[u] ? p[u] = gp(p[u]) : u;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i += 1) cin >> a[i];
    for(int i = 1; i <= m; i += 1) cin >> b[i];
    vector<Edge> edges;
    for(int i = 1, s, k; i <= n; i += 1){
        for(cin >> s; s; s -= 1){
            cin >> k;
            edges.push_back({i, k + n, a[i] + b[k]});
        }
    }
    sort(edges.begin(), edges.end(), [](const Edge& x, const Edge& y){
        return x.w > y.w;
    });
    LL ans = 0;
    for(auto e : edges){
        int pu = gp(e.u), pv = gp(e.v);
        if(pu != pv) p[pu] = pv;
        else ans += e.w;
    }
    cout << ans;
    return 0;
}