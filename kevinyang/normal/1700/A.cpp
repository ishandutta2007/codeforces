#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		int ans = m*(m+1)/2+m*n*(n+1)/2-m;
		cout << ans << "\n";
	}
	return 0;
}