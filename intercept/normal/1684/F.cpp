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
int n,m;
int a[M],c[M],p[M],b[M],f[M][23];
vector<int>g[M],h[M];
int get(int x,int r){
    for(int j=19;j>=0;--j){
        if(f[x][j]<=r)x=f[x][j];
    }
    return x;
}
void work(){
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>a[i],c[i]=a[i],g[i].clear(),h[i].clear();
    sort(c+1,c+n+1);
    int num=unique(c+1,c+n+1)-c-1;
    for(int i=1;i<=n;++i){
        a[i]=lower_bound(c+1,c+num+1,a[i])-c;
    }
    for(int i=1;i<=n;++i)b[i]=n+1;
    f[n+1][0]=p[n+1]=n+1;
    for(int j=1;j<=19;++j)f[n+1][j]=n+1;
    for(int i=n;i>=1;--i){
        p[i]=b[a[i]];
        b[a[i]]=i;
        f[i][0]=p[i];
        for(int j=1;j<=19;++j)f[i][j]=f[f[i][j-1]][j-1];
    }
    for(int i=1;i<=m;++i){
        int l,r;
        cin>>l>>r;
        g[l].eb(r);
    }
    int r=0,R=0,L=n;
    for(int l=1;l<=n;++l){
        for(auto o:g[l]){
            r=max(r,o);
        }
        if(r<l)continue;
        int x=get(l,r);
        int y=get(l,x-1);
        if(x==l)continue;
        R=max(R,y);
        h[l].eb(x);
        L=min(L,p[l]);
    }
    int ans=n;
    for(int l=1;l<=n;++l){
        if(l>L||l>R+1)break;
        ans=min(ans,R-l+1);
        for(auto o:h[l]){
            R=max(R,o);
        }
    }
    cout<<ans<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--)work();
    return 0;
}

/*
1
5 2
10 1 6 14 1
4 5
2 4
*/