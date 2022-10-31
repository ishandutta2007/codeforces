#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef long long ll;
const int N = 1e5+7;
const int K = 21;
vector<int> G[N];
ll clk[N][2][K],A[N];
int n,k;
void dfs(int v,int par){
    clk[v][0][0]^=A[v];
    for(int to:G[v]){
        if (to==par)
            continue;
        dfs(to,v);
        for(int c = 0;c<2;++c){
            for(int i = 1;i<k;++i){
                clk[v][c][i]^=clk[to][c][i-1];
            }
            clk[v][c][0]^=clk[to][c^1][k-1];
        }
    }
}
int ans[N];
void copy(ll (&a)[2][21],ll (&b)[2][21]){
    for(int i = 0;i<2;++i){
        for(int j = 0;j<k;++j)
            a[i][j] = b[i][j];
    }
}
void solve(int v,int par){

    for(int c = 0;c<2;++c){
        for(int j = 0;j<=k;++j)
            clk[v][c][j] = 0;
    }
    clk[v][0][0]^=A[v];
    for(int to:G[v]){
        for(int c = 0;c<2;++c){
            for(int i = 1;i<k;++i){
                clk[v][c][i]^=clk[to][c][i-1];
            }
            clk[v][c][0]^=clk[to][c^1][k-1];
        }
    }
    ll res = 0;
    for(int i = 0;i<k;++i){
        res^=clk[v][1][i];
    }
    ans[v] = (res!=0);
    for(int to:G[v]){
        if (to==par)
            continue;
        ll c1[2][K],c2[2][K];
        copy(c1,clk[v]);
        copy(c2,clk[to]);
        for(int c = 0;c<2;++c){
            for(int i = 1;i<k;++i){
                clk[v][c][i]^=clk[to][c][i-1];
            }
            clk[v][c][0]^=clk[to][c^1][k-1];
        }
        solve(to,v);
        copy(clk[v],c1);
        copy(clk[to],c2);
    }
}
signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n>>k;
    for(int i = 1;i<n;++i){
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i = 1;i<=n;++i)
        cin>>A[i];
    dfs(1,1);
    solve(1,1);
    for(int i = 1;i<=n;++i){
        cout<<ans[i]<<' ';
    }
    cout<<endl;
    return 0;
}