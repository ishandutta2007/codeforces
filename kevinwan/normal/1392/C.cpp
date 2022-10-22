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
const int mn=2e5+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll mod=998244353;
ll a[mn];
int main(){
#ifdef LOCAL_PROJECT
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
#endif
    cin.tie(0);
    cin.sync_with_stdio(0);
    int tc;
    cin>>tc;
    while(tc--){
        ll n;
        cin>>n;
        for(int i=0;i<n;i++)cin>>a[i];
        ll ans=0;
        for(int i=0;i+1<n;i++){
            ans+=max(0LL,a[i]-a[i+1]);
        }
        printf("%lld\n",ans);
    }
}