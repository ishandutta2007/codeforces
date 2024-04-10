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
const int M=1009;
int n,m,ans;
ll a[M];
vector<int>g[M];
int be[M];
bool vis[M];
bool dfs(int u){
    for(auto v:g[u]){
        if(!vis[be[v]]){
            vis[be[v]]=1;
            if(!be[v]||dfs(be[v])){
                be[v]=u;
                be[u]=v;
                return 1;
            }
        }
        
    }
    return 0;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    int s=0;
    for(int i=1;i<=n;++i){
        if(a[i]*3>m){
            s++;
            for(int j=1;j<=n;++j){
                if(a[i]*3>m){
                    if(a[i]+a[i]+a[j]<=m){
                        if(a[i]%a[j]==0){
                            g[i].eb(j);
                        }
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;++i){
        memset(vis,0,sizeof(vis));
        if(a[i]*3>m)ans+=dfs(i);
    }
    if(ans!=s){
        puts("-1");
    }
    else{
        vector<pair<ll,ll>>p;
        for(int i=1;i<=n;++i){
            if(!be[i])p.eb(a[i]*3,a[i]*2);
            else{
                if(a[i]*3>m){
                    p.eb(a[i]+a[i]+a[be[i]],a[be[i]]+a[i]);
                }
            }
        }
        cout<<p.size()<<endl;
        for(auto o:p){
            cout<<o.fi<<" "<<o.se<<endl;
        }
    }
    return 0;
}
/*
8 2000
100 100 100 100 100 900 900 900
*/