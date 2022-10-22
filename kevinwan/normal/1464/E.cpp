#include "bits/stdc++.h"
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef __int128 lll;
typedef vector<int> vi;
typedef vector<ll> vl;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const ll inf=0x3f3f3f3f3f3f3f3f;
const int mn=1<<17;
const ll mod=998244353;
ll po(ll a,ll b=mod-2){
    ll ans=1;
    for(;b;b>>=1,a*=a,a%=mod)if(b&1)ans*=a,ans%=mod;
    return ans;
}
vector<ll> FWHT(vector<ll> p, bool inverse=0) {
    int n=p.size();
    for (int len = 1; 2 * len <= n; len <<= 1) {
        for (int i = 0; i < n; i += 2 * len) {
            for (int j = 0; j < len; j++) {
                ll u = p[i + j];
                ll v = p[i + len + j];
                p[i + j] = (u + v)%mod;
                p[i + len + j] = (u - v)%mod;
            }
        }
    }
    
    if (inverse) {
        for (int i = 0; i < n; i++)
            p[i] = p[i] *po(n)%mod;
    }

    return p;
}
bool vis[mn];
int hail[mn],num[mn];
vector<int>g[mn];
void dfs(int x){
    vis[x]=1;
    for(int y:g[x])if(!vis[y])dfs(y);
    set<int>s;
    for(int y:g[x])s.insert(hail[y]);
    for(int i=0;s.find(i)!=s.end();i++,hail[x]++);
    num[hail[x]]++;
}
int main(){
#ifdef LOCAL
    freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
freopen("error.txt","w",stderr);
#endif
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
    }
    for(int i=1;i<=n;i++)if(!vis[i])dfs(i);
    vector<ll>p(mn);
    for(int i=0;i<mn;i++)p[i]=num[i]*po(n+1)%mod;
    cerr<<num[0]<<endl;
    cerr<<p[0]*2%mod<<endl;
    for(int i=0;i<mn;i++)p[i]=-p[i];
    p[0]++;
    p=FWHT(p);
    for(int i=0;i<mn;i++)p[i]=po(p[i]);
    p=FWHT(p,1);
    for(int i=0;i<mn;i++)p[i]=p[i]*po(n+1)%mod;
    ll ans=(1-p[0])%mod;
    if(ans<0)ans+=mod;
    cout<<ans;
}