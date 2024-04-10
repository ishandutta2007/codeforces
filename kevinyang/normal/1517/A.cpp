#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		if(n%2050){
			cout << "-1\n";
		}
		else{
			int x = n/2050;
			int ans = 0;
			while(x>0){
				ans+=x%10; x/=10;
			}
			cout << ans << "\n";
		}
	}
	return 0;
}