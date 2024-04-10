#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define fors(i, a, b) for(int i = (a); i < (b); ++i)
using namespace std;
const int maxn = 2e5 + 5;
vector<int> g[maxn];
int n;
int dp[maxn], h[maxn];
void init(){
    scanf("%d", &n); fors(i,0,n+1) g[i].clear();
    fors(i,1,n){
        int u, v; scanf("%d%d", &u, &v); g[u].pb(v); g[v].pb(u);
    }
}
void dfs(int u, int f){
    if(g[u].size()==1 && u != 1){ h[u] = dp[u] = 0; return;}
    h[u] = 1e9; dp[u] = 0;
    int fi = -n, se = -n;
    for(int v: g[u]){
        if(v == f) continue;
        dfs(v, u);
        dp[u] = max(dp[u], dp[v]);
        if(h[v] >= fi) se = fi, fi = h[v];
        else if(h[v] > se) se = h[v];
        h[u] = min(h[u], h[v]+1);
    }
    if(u == 1) dp[u] = max(dp[u], fi+1);
    else dp[u] = max(dp[u], fi+2);
    dp[u] = max(dp[u], se+2);
    return;
}
void sol(){
    dfs(1, 0);
    printf("%d\n", dp[1]);
}
int main()
{
    int T; cin>>T;
    while(T--){
        init(); sol();
    }
}
/*
3
8
1 2
2 3
1 4
4 5
1 6
6 7
7 8
*/