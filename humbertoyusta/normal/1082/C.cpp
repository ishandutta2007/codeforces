#include<bits/stdc++.h>
#define maxn 100005
using namespace std;

int n,m,ans[maxn],u,v,res;
vector<int> g[maxn];

bool fcmp(int a,int b){ return a > b; }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ///freopen("a.in","r",stdin);

    cin >> n >> m;

    for(int i=1; i<=n; i++){
        cin >> u >> v;
        g[u].push_back(v);
    }

    for(int i=1; i<=m; i++)
        sort(g[i].begin(),g[i].end(),fcmp);

    for(int i=1; i<=m; i++){

        if(g[i].size()>=1)
            if(g[i][0]>0)
                ans[0]+=g[i][0];

        for(int j=1; j<g[i].size(); j++){
            g[i][j] = g[i][j-1] + g[i][j];
            if( g[i][j] > 0 )
                ans[j] += g[i][j];
        }
    }

    int res=0;
    for(int i=0; i<=n; i++)
        res=max(res,ans[i]);

    cout << res << '\n';

    return 0;
}