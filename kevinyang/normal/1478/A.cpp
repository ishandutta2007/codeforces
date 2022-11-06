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
		vector<int>freq(101);
		for(int i = 0; i<n; i++){
			int x;
			cin >> x; freq[x]++;
		}
		int ans = 0;
		for(int i = 0; i<=100; i++){
			ans = max(ans,freq[i]);
		}
		cout << ans << "\n";
	}
	return 0;
}