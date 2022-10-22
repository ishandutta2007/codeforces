#include "bits/stdc++.h"
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef __int128 lll;
typedef vector<int> vi;
typedef vector<ll> vl;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

const int mn=3e5+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;
ll a[mn],c[mn];
ll eval(ll x,ll k){
    ll q=x/k,r=x%k;
    return (q+1)*(q+1)*r+q*q*(k-r);
}
int main(){
    #ifdef LOCAL
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
freopen("error.txt","w",stderr);
    #endif
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,k;
    cin>>n>>k;
    set<pll>s;
    for(int i=1;i<=n;i++)cin>>a[i],c[i]=1;
    ll ans=0;
    for(int i=1;i<=n;i++){
        s.insert({eval(a[i],c[i])-eval(a[i],c[i]+1),i});
        ans+=eval(a[i],1);
    }
    for(int i=0;i<k-n;i++){
        pll p=*prev(s.end());
        s.erase(prev(s.end()));
        c[p.second]++;
        ans-=p.first;
        s.insert({eval(a[p.second],c[p.second])-eval(a[p.second],c[p.second]+1),p.second});
    }
    printf("%lld\n",ans);
}