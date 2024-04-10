#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1 << 20;
const ll mod = 1e9+7;
const ll inf = 0x3f3f3f3f3f3f3f3f;
ll pa[N];
ll find(ll a){
    return pa[a]==a?a:pa[a]=find(pa[a]);
}

void merge(ll a,ll b){
    a=find(a);
    b=find(b);
    pa[a]=b;
}
ll a[N],b[N],k[N];
ll top[N];
ll qpow(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1) ans=(ans*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return ans;
}
ll cnt[N];
int main(){
    ios::sync_with_stdio(0);
    for(ll i=0;i<N;i++) pa[i]=i;
    ll n,m;
    cin>>n>>m;
    vector<ll> v;
    for(ll i=1;i<=n;i++){
        cin>>k[i];
        if(k[i]==1) cin>>a[i];
        else cin>>a[i]>>b[i];
        if(k[i]==1){
            if(find(a[i])!=find(m+1)){
                v.push_back(i);
                merge(a[i],m+1);
            }
        }else {
            if(find(a[i])!=find(b[i])) v.push_back(i);
            merge(a[i],b[i]);
        }
    }
    ll ans=0;
    for(ll i=1;i<=m+1;i++){
        cnt[find(i)]++;
    }
    for(ll i=1;i<=m+1;i++){
        if(cnt[i]==0) continue;
        ans+=cnt[i]-1;
    }
    cout<<qpow(2,ans)<<' '<<v.size()<<endl;
    for(auto x:v) cout<<x<<' ';
    cout<<endl;
}