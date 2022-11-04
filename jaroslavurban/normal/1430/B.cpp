#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const int N=200100;
ll a[N];

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tt;cin>>tt;
	while(tt--){
		ll n,k;cin>>n>>k;
		for(int i=0;i<n;++i)cin>>a[i];
		sort(a,a+n);
		if(!k){
			cout<<a[n-1]-a[0]<<endl;
			continue;
		}
		for(int i=n-2;i>=0&&k--;--i)a[n-1]+=a[i];
		cout<<a[n-1]<<endl;
	}
}