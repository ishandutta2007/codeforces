#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

signed main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		ll a;cin>>a;
		while(!(a%2))a/=2;
		cout<<(a==1?"NO\n":"YES\n");
	}
}