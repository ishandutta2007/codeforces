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
const int M=300009;
int n;
int a[M],siz[M],b[M],f[M],c[M];
vector<int>g[M];
void dfs(int u,int fa){
    siz[u]=a[u];
    f[u]=(c[fa]||!fa)?u:f[fa];
    for(auto v:g[u]){
        if(v!=fa){
            dfs(v,u);
            siz[u]+=siz[v];
            b[u]|=b[v];
        }
    }
    if(a[u]&&siz[u]>1)b[u]=1;
    for(auto v:g[u]){
        if(a[v]){
            if(siz[u]-siz[v]>0)b[u]=1;
        }
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<n;++i){
        int u,v;
        cin>>u>>v;
        g[u].eb(v);
        g[v].eb(u);
    }
    for(int i=1;i<=n;++i){
        if(a[i]){
            c[i]=1;
            for(auto v:g[i])c[v]=1;
        }
    }
    dfs(1,0);
    siz[0]=siz[1];
    for(int i=1;i<=n;++i){
        bool flag=c[i];
        int x=f[i];
        if(b[x]||siz[1]-siz[x]>1)flag=1;
        cout<<flag<<" ";
    }
    return 0;
}
/*


*/