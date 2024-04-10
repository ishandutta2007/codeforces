#include<bits/stdc++.h>
#define ll long long
#define eb emplace_back
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int M=109;
const int mod=998244353;
int n;
int dp[M][M];
int x[M],y[M],f[M];
int dis(int i,int j){
    return abs(x[i]-x[j])+abs(y[i]-y[j]);
}
int find(int x){
    return f[x]==x?x:f[x]=find(f[x]);
}
void merge(int x,int y){
    if(find(x)==find(y))return;
    f[find(x)]=find(y);
}
int vis[M][M],d[M];
vector<int>g[M],v;
int main(){
    cin>>n;
    for(int i=1;i<=n;++i){
        f[i]=i;
        cin>>x[i]>>y[i];
    }
    for(int i=1;i<=n;++i){
        int ma=2e9+9;
        for(int j=1;j<=n;++j){
            if(i!=j)ma=min(ma,dis(i,j));
        }
        for(int j=1;j<=n;++j){
            if(dis(i,j)==ma&&i!=j)vis[i][j]=1,d[i]++;
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(vis[i][j]&&vis[j][i])merge(i,j);
        }
    }
    for(int i=1;i<=n;++i){
        g[find(i)].eb(i);
    }
    for(int i=1;i<=n;++i){
        if(g[i].size()<2){
            for(auto o:g[i])v.eb(1);
            continue;
        }
        int ma=dis(g[i][0],g[i][1]);
        bool flag=1;
        for(int j=0;j<g[i].size();++j){
            if(d[g[i][j]]+1!=g[i].size())flag=0;
            for(int k=j+1;k<g[i].size();++k){
                if(dis(g[i][j],g[i][k])!=ma)flag=0;
            }
        }
        if(!flag){
            for(auto o:g[i])v.eb(1);
        }
        else v.eb(g[i].size());
    }
    dp[0][n+1]=1;
    for(int i=1;i<=v.size();++i){
        int x=v[i-1];
        for(int j=0;j<=n;++j){
            int rex=1;
            for(int k=j;k<j+x;++k)rex=1ll*rex*k%mod;
            dp[i][j]=(dp[i][j]+1ll*dp[i-1][j+x]*rex%mod)%mod;
            if(x>1)dp[i][j]=(dp[i][j]+1ll*dp[i-1][j+1]*j%mod)%mod;
        }
    }
    int ans=0;
    for(int i=0;i<=n;++i){
        ans=(ans+dp[v.size()][i])%mod;
    }
    cout<<ans<<endl;
    return 0;
}
/*
4
10 0
0 10
10 20
20 10
*/