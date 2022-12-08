#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
int main()
{
	cin>>n>>m;
	ll mn=max(n-m*2,0ll);
	ll mx=0;
	for(ll i=0;i<=n;i++){
		if(i*(i-1)/2>=m){
			//cout<<i*(i-1)/2;
			mx=i;break;
		}
	}
	mx=n-mx;
	printf("%lld %lld\n",mn,mx);
}