#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int mn = 3e5+10;
const ll mod = 1e9+7;
const int SIZE = 400;

ll a[mn],b[mn];

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	int n,p,k;
	cin>>n>>p>>k;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++){
		b[i]=a[i]*a[i]%p*a[i]%p*a[i]%p-k*a[i]%p;
		b[i]%=p;
		if(b[i]<0)b[i]+=p;
		//cerr<<b[i];
	}
	sort(a,a+n);
	sort(b,b+n);
	ll ans=0;
	a[n]=b[n]=-1;
	int num=0;
	for(int i=0;i<n;i++){
		num++;
		if(b[i]!=b[i+1]){
			ans+=1LL*num*(num-1)/2;
			num=0;
		}
	}
	printf("%lld\n",ans);
}