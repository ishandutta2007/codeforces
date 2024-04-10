#include<bits/stdc++.h>
#ifndef LOCAL_PROJECT
#define cerr if(0)cerr
#endif
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef __int128 lll;
const lll ONE=1;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=1e5+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;
ll bas[60],nb[60];
bool add(ll x){
    for(int i=59;i>=0;i--)if((x>>i)&1){
        if(bas[i])x^=bas[i];
        else {bas[i]=x;return 1;}
    }
    return 0;
}
vector<int>g[mn];
vector<ll>w[mn];
bool vis[mn];
ll val[mn];
ll bnum,num;
vector<int>v;
void dfs(int x){
    vis[x]=1;
    v.push_back(x);
    num++;
    for(int i=0;i<g[x].size();i++){
        int y=g[x][i];
        if(!vis[y])val[y]=val[x]^w[x][i],dfs(y);
        else{
            bnum+=add(val[x]^val[y]^w[x][i]);
        }
    }
}
ll i2=(mod+1)/2;
int main(){
#ifdef LOCAL_PROJECT
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
#else
    cin.tie(0);
    cin.sync_with_stdio(0);
#endif
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        ll c;
        cin>>a>>b>>c;
        g[a].push_back(b);
        g[b].push_back(a);
        w[a].push_back(c);
        w[b].push_back(c);
    }
    ll ans=0;
    for(int i=1;i<=n;i++)if(!vis[i]){
        v.clear();
        num=bnum=0;
        memset(nb,0,sizeof(nb));
        memset(bas,0,sizeof(bas));
        dfs(i);
        for(int x:v){
            for(int i=0;i<60;i++)if((val[x]>>i)&1)nb[i]++;
        }
        for(int i=0;i<60;i++)nb[i]=nb[i]*(num-nb[i]);
        ll o=0;
        for(int i=0;i<60;i++)o|=bas[i];
        for(int i=0;i<60;i++){
            if((o>>i&1)){
                ans+=(1LL<<i)%mod*(num*(num-1)/2%mod)%mod*((1LL<<(bnum-1))%mod)%mod;
            }
            else{
                ans+=(1LL<<i)%mod*nb[i]%mod*((1LL<<(bnum))%mod)%mod;
            }
            ans%=mod;
        }
    }
    printf("%lld",ans);
}