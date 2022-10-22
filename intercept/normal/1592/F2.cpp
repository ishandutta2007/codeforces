#include<bits/stdc++.h>
#define ll long long 
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int mod=1e9+7;
int kpow(int x,int y,int rex=1){
    for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)rex=1ll*x*rex%mod;
    return rex;
}
int exgcd(int a,int b,int &x,int &y){
    int t=b?exgcd(b,a%b,y,x):a;
    if(!b)x=1,y=0;
    else y-=a/b*x;
    return t;
}
const int M=509;
int n,m;
char s[M][M];
bool b[M][M],d[M],c[M][M];
int ans=0;
vector<int>g[M];
int be[M];
bool vis[M];
bool dfs(int u){
    for(auto v:g[u]){
        if(!vis[be[v]]){
            vis[be[v]]=1;
            if(!be[v]||dfs(be[v])){
                be[v]=u;
                return 1;
            }
        }
        
    }
    return 0;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>(s[i]+1);
    }
    for(int i=n;i>=1;--i){
        bool z=0;
        for(int j=m;j>=1;--j){
            bool o=z^(s[i+1][j]=='B');
            if(o!=(s[i][j]=='B')){
                ans++;
                z^=1;
                c[i][j]=1;
            }
        }
    }
    for(int i=1;i<n;++i){
        for(int j=1;j<m;++j){
            if(c[i][j]&&c[i][m]&&c[n][j]){
                g[i].eb(j);
            }
        }
    }
    ans-=c[n][m];
    for(int i=1;i<n;++i){
        memset(vis,0,sizeof(vis));
        if(dfs(i)){
            ans--;
            c[n][m]^=1;
        }
    }
    ans+=c[n][m];
    cout<<ans<<endl;
    return 0;
}
/*
3 3
WWW
WBB
WBW
*/