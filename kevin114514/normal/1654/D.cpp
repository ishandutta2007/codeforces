#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
const int MAXN=2e5+10,mod=998244353,LIM=2e5;
ll mypow(ll a,ll n){
    if(!n)return 1;
    ll tmp=mypow(a,n/2);tmp=tmp*tmp%mod;
    if(n&1)tmp=tmp*a%mod;return tmp;
}
int prime[MAXN],minp[MAXN],tot;
ll inver[MAXN];
vector<int>d[MAXN];
void pre(){
    rep(i,1,LIM)inver[i]=mypow(i,mod-2);
    rep(i,2,LIM){
        if(!minp[i]){
            minp[i]=i;prime[++tot]=i;
        }
        rep(j,1,tot){
            if(prime[j]*i>LIM)break;
            minp[prime[j]*i]=prime[j];
            if(i%prime[j]==0)break;
        }
    }
    rep(i,2,LIM){
        int u=i;
        while(minp[u]){
            d[i].push_back(minp[u]);
            u/=minp[u];
        }
    }
}
int T,n;
int bucket[MAXN],maxn[MAXN],tag[MAXN];
ll val,ans;
vector<array<int,3> >e[MAXN];
void dfs1(int u,int fa){
    for(auto p:e[u]){
        int v=p[0],x=p[1],y=p[2];
        if(v==fa)continue;  
        for(auto u:d[x])bucket[u]--;
        for(auto u:d[y]){
            bucket[u]++;
            if(maxn[u]<bucket[u]){
                maxn[u]=bucket[u];
                val=val*u%mod;
            }
        }
        dfs1(v,u);
        for(auto u:d[x])bucket[u]++;
        for(auto u:d[y])bucket[u]--;
    }
}
void dfs2(int u,int fa,ll val){
    ans=(ans+val)%mod;
    for(auto p:e[u]){
        int v=p[0],x=p[1],y=p[2];
        if(v==fa)continue;
        dfs2(v,u,val*x%mod*inver[y]%mod);
    }
}
void solve(){
    val=1;
    cin>>n;
    rep(i,1,n){for(auto u:d[i])bucket[u]=maxn[u]=tag[u]=1;}
    rep(i,1,n)e[i].clear();
    rep(i,1,n-1){
        int u,v,x,y;cin>>u>>v>>x>>y;
        e[u].push_back({v,y,x});
        e[v].push_back({u,x,y});
    }
    dfs1(1,0);
    ans=0;
    dfs2(1,0,val);
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    pre();
    cin>>T;
    while(T--){
        solve();
    }

    return 0;
}