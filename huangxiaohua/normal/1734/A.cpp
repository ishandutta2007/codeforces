#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll i,j,k,n,m,t,a[666],res;

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+n+1);
		res=1e18;
		ll x,y,z;
		for(i=3;i<=n;i++){
			x=a[i-2];y=a[i-1];z=a[i];
			res=min(res,abs(x-x)+abs(x-y)+abs(x-z));
			res=min(res,abs(y-x)+abs(y-y)+abs(y-z));
			res=min(res,abs(z-x)+abs(z-y)+abs(z-z));
		}
		cout<<res<<'\n';
	}
}