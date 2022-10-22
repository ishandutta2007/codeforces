#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
using namespace std;
const int M=1e5+9;
int n,m;
vector<int>g[M];
vector<pii>ans;
void dfs(int u,int fa,int t){
    ans.eb(u,t);
    int x=t;
    if(x==m&&x!=0){
        x=m-g[u].size();
        ans.eb(u,x);
    }
    for(auto v:g[u]){
        if(v!=fa){
            dfs(v,u,x+1);
            x++;
            ans.eb(u,x);
            if(x==m&&u!=1){
                x=m-g[u].size();
                ans.eb(u,x);
            }
        }
    }
    if(x!=t-1&&t!=0&&u!=1){
        ans.eb(u,t-1);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<n;++i){
        int u,v;
        cin>>u>>v;
        g[u].eb(v);
        g[v].eb(u);
    }
    for(int i=1;i<=n;++i)m=max(m,(int)g[i].size());
    dfs(1,0,0);
    cout<<ans.size()<<"\n";
    for(auto o:ans){
        cout<<o.fi<<" "<<o.se<<"\n";
    }
    return 0;
}