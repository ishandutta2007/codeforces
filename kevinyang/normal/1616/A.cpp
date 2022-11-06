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
		vector<int>freq(105);
		for(int i = 0; i<n; i++){
			int x;
			cin >> x;
			x = abs(x);
			freq[x]++;
		}
		int ans = 0;
		for(int i = 1; i<=100; i++){
			ans+=min(2LL,freq[i]);
		}
		ans+=min(1LL,freq[0]);
		cout << ans << "\n";
	}
	return 0;
}