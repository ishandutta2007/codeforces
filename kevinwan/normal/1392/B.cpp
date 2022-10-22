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
        ll n,k;
        cin>>n>>k;
        for(int i=0;i<n;i++)cin>>a[i];
        ll mi=inf,ma=-inf;
        for(int i=0;i<n;i++)mi=min(mi,a[i]),ma=max(ma,a[i]);
        if(k&1){
            for(int i=0;i<n;i++)a[i]=ma-a[i];
        }
        else{
            for(int i=0;i<n;i++)a[i]=a[i]-mi;
        }
        for(int i=0;i<n;i++)printf("%lld ",a[i]);
        printf("\n");
    }
}