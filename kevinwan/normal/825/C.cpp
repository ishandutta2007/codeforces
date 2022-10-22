#include<bits/stdc++.h>
#ifndef LOCAL_PROJECT
#define cerr if(0)cerr
#endif
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll mod=998244353;
const int mn=1e3+10;
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
    ll n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
    	cin>>a[i];
    }
    sort(a,a+n);
    ll ans=0;
    for(int i=0;i<n;i++){
    	while(2*k<a[i])ans++,k*=2;
    	k=max(k,a[i]);
    }
    printf("%lld",ans);
}