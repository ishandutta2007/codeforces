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
const int M=2e5+9;
int n,m,k;
int a[M],p[M],vis[M],s[M],f[M][33];
int in[M];
int g[M],pa[M],ans[M];
int get(int x){
    for(int j=29;j>=0;--j){
        if(k>>j&1)x=f[x][j];
    }
    return x;
}
int find(int x){
    return pa[x]==x?x:pa[x]=find(pa[x]);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&p[i]);
        if(vis[p[i]])m++;
        vis[p[i]]=1;
        f[i][0]=p[i];
    }
    int ma=0;
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
        ma=max(ma,a[i]);
    }
    k=(ma-n)/m;
    for(int j=1;j<30;++j){
        for(int i=1;i<=n;++i)f[i][j]=f[f[i][j-1]][j-1];
    }
    for(int i=1;i<=n;++i)pa[i]=i;
    for(int i=1;i<=n;++i){
        int x=get(i);
        if(a[x]<=n){
            s[i]=a[x];
            if(g[a[x]]==0){
                g[a[x]]=1;
                int y=find(a[x]);
                pa[y]=find(y+1);
                ans[i]=a[x];
            }
        }
        else s[i]=1;
    }
    for(int i=1;i<=n;++i){
        if(ans[i])continue;
        int x=find(s[i]);
        ans[i]=x;
        pa[x]=find(x+1);
    }
    
    for(int i=1;i<=n;++i)printf("%d%c",ans[i]," \n"[i==n]);
    return 0;
}