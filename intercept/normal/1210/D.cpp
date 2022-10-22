#include<bits/stdc++.h>
#define ll long long 
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int mod=998244353;
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
const int M=1000009;
int n,m,q;
int d[M];
vector<int>g[M];
ll ans;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        d[u]++;
        d[v]++;
        if(u>v)swap(u,v);
        g[u].eb(v);
    }
    for(int u=1;u<=n;++u){
        ans+=(d[u]-g[u].size())*g[u].size();
    }
    printf("%lld\n",ans);
    scanf("%d",&q);
    for(int i=1;i<=q;++i){
        int u;
        scanf("%d",&u);
        ans-=(d[u]-g[u].size())*g[u].size();
        for(auto v:g[u]){
            ans-=g[v].size();
            g[v].eb(u);
            ans+=d[v]-g[v].size();
        }
        g[u].clear();
        printf("%lld\n",ans);
    }
    return 0;
}
/*

4 5
1 2
2 4
1 3
3 4
2 3
1
2

*/