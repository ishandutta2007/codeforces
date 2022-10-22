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
const int mn=4e5+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;
ll a[mn];
int main(){
#ifdef LOCAL_PROJECT
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
#else
    cin.tie(0);
    cin.sync_with_stdio(0);
#endif
    int n;
    cin>>n;
    ll sum=0;
    for(int i=0;i<n;i++)cin>>a[i],a[i+n]=a[i],sum+=a[i];
    for(int i=2;i<n*2;i++)a[i]+=a[i-2];
    ll ans=inf;
    for(int i=n-1;i<n*2;i++)ans=min(ans,a[i]-a[i-(n-1)]);
        printf("%lld",sum-ans);
}