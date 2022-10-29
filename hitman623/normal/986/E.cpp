#include <bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int expo(int base,int exponent,int mod){
    int ans=1;
    while(exponent!=0){
        if(exponent&1) ans=(1LL*ans*base)%mod;
        base=(1LL*base*base)%mod;
        exponent>>=1;
    }
    return ans%mod;
}
int n,q,val[100005],p[100005],dp[20][100005],h[100005],freq[10000007],ans[100006],vis[10000007];
vii factors[10000007],queries[100005];
vi a[100005];
void dfs1(int node,int par){
    p[node]=par;
    h[node]=h[par]+1;
    for(auto i:a[node]){
        if(i!=par){
            dfs1(i,node);
        }
    }
}
void pre_lca(){
    rep(i,1,n+1) dp[0][i]=p[i];
    rep(i,1,18){
        rep(j,1,n+1){
            dp[i][j]=dp[i-1][dp[i-1][j]];
        }
    }
}
int spf[10000007];
void pre(){
    rep(i,2,10000001) spf[i]=i;
    rep(i,2,4000){
        if(spf[i]!=i) continue;
        for(int j=i*i;j<=10000000;j+=i){
            if(spf[j]==j) spf[j]=i;
        }
    }
    rep(i,2,10000001){
        if(vis[i]==0) continue;
        int d=i;
        while(d!=1){
            int cnt=0,p=spf[d];
            while(d%p==0) cnt++,d/=p;
            factors[i].pb({p,cnt});
        }
    }
}
int lca(int u,int v){
    if(h[u]>h[v])swap(u,v);
    for(int i=17;i>=0;i--){
        if(h[v]-(1<<i)>=h[u])v=dp[i][v];
    }
    if(u==v)return u;
    for(int i=17;i>=0;i--){
        if(dp[i][u]!=dp[i][v])u=dp[i][u],v=dp[i][v];
    }
    return dp[0][u];
}
void dfs2(int node){
    for(auto i:factors[val[node]]){
        int cur=1;
        rep(j,0,i.y+1){
            freq[cur]++;
            cur*=i.x;
        }
    }
    for(auto i:queries[node]){
        int g=1;
        for(auto j:factors[i.x]){
            int cur=0,v=1;
            rep(k,0,j.y) v*=j.x;
            for(int k=j.y;k>=0;k--){
                g=1LL*g*expo(v,freq[v]-cur,hell)%hell;
                cur=freq[v];
                v/=j.x;
            }
        }
        if(i.y>0) ans[i.y]=1LL*ans[i.y]*g%hell;
        else ans[-i.y]=1LL*ans[-i.y]*expo(1LL*g*g%hell,hell-2,hell)%hell;
    }
    for(auto i:a[node]){
        if(i!=p[node]){
            dfs2(i);
        }
    }
    for(auto i:factors[val[node]]){
        int cur=1;
        rep(j,0,i.y+1){
            freq[cur]--;
            cur*=i.x;
        }
    }
}
void solve(){
    cin>>n;
    rep(i,0,n-1){
        int u,v;
        cin>>u>>v;
        a[u].pb(v);
        a[v].pb(u);
    }
    dfs1(1,1);
    pre_lca();
    rep(i,1,n+1) cin>>val[i],vis[val[i]]=1;
    cin>>q;
    rep(i,1,q+1){
        int u,v,x;
        cin>>u>>v>>x;
        queries[u].pb({x,i});
        queries[v].pb({x,i});
        int w=lca(u,v);
        queries[w].pb({x,-i});
        ans[i]=__gcd(val[w],x);
        vis[x]=1;
    }
    pre();
    dfs2(1);
    rep(i,1,q+1) cout<<ans[i]<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}