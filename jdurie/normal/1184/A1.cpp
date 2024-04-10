#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;

int main() {
				  ios_base::sync_with_stdio(false);
					  cin.tie(NULL);

	ll r;
	cin>>r;
	for (ll x=1; x<=1000000; x++) {
		ll w = r-x*x-x-1;
		if (w%(2*x)==0 && w>0) {
			cout<<x<<" "<<w/x/2<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
}