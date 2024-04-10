// luogu remote judge
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int inf=1e9;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vector<int>>dis(n,vector<int>(n,inf));
    for(int i=0;i<n;++i){
        dis[i][i]=0;
    }
    for(int i=0;i<m;++i){
        int u,v;
        cin>>u>>v;
        --u;
        --v;
        dis[u][v]=1;
        dis[v][u]=1;
    }
    for(int k=0;k<n;++k){
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    int s,b,k,h;
    cin>>s>>b>>k>>h;
    vector<tuple<int,int,int>>ship(s);
    for(auto &i:ship){
        cin>>get<0>(i)>>get<1>(i)>>get<2>(i);
        --get<0>(i);
    }
    vector<pair<int,int>>base(b);
    for(auto &i:base){
        cin>>i.first>>i.second;
        --i.first;
    }
    vector<vector<bool>>con(s,vector<bool>(b));
    for(int i=0;i<s;++i){
        for(int j=0;j<b;++j){
            if(get<1>(ship[i])>=base[j].second&&get<2>(ship[i])>=dis[get<0>(ship[i])][base[j].first]){
                con[i][j]=true;
            }
        }
    }
    vector<int>yx(b,-1);
    vector<bool>used(b,false);
    function<bool(int)> dfs=[&](int x){
        for(int y=0;y<b;++y){
            if(con[x][y]&&!used[y]){
                used[y]=true;
                if(yx[y]==-1||dfs(yx[y])){
                    yx[y]=x;
                    return true;
                }
            }
        }
        return false;
    };
    int match=0;
    for(int i=0;i<s;++i){
        match+=dfs(i);
        used.assign(b,false);
    }
    ll ans=min(1ll*match*k,1ll*s*h);
    cout<<ans<<endl;
    return 0;
}