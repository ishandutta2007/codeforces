#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int l,r;
		cin >> l >> r;
		int ans = 0;
		while(r>0){
			ans+=r;
			r/=10;
		}
		while(l>0){
			ans-=l;
			l/=10;
		}
		cout << ans << "\n";
	}
	return 0;
}