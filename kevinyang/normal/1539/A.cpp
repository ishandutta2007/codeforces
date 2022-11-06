#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int k;
	cin >> k;
	while(k--){
		int n,x,t;
		cin >> n >> x >> t;
		int v = t/x;
		if(v>n){
			cout << n*(n-1)/2 << "\n";
			continue;
		}
		int ans = n*v - v*(v+1)/2;
		cout << ans << "\n";
	}
	return 0;
}