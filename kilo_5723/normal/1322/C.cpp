#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int maxn=5e5+5;
inline ll gcd(ll a,ll b){
    while (b){ a%=b; swap(a,b); }
    return a;
}
ll a[maxn],b[maxn];
ll mpow[maxn];
map<ll,ll> mp;
int main(){
    int tt;
    int i,n,m;
    int u,v;
    ll ans;
    scanf("%d",&tt);
    mpow[0]=1;
    for (i=1;i<maxn;i++) mpow[i]=mpow[i-1]*2%mod;
    while (tt--){
        scanf("%d%d",&n,&m);
        for (i=1;i<=n;i++) scanf("%lld",&a[i]);
        for (i=1;i<=n;i++) b[i]=0;
        while (m--){
            scanf("%d%d",&u,&v);
            b[v]+=mpow[u];
        }
        mp.clear();
        for (i=1;i<=n;i++) if (b[i]) mp[b[i]]+=a[i];
        ans=0;
        for (auto pr:mp) ans=gcd(ans,pr.second);
        printf("%lld\n",ans);
    }
    return 0;
}