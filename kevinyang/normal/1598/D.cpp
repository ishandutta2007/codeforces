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
		vector<pair<int,int>>arr(n+1);
		for(int i = 1; i<=n; i++){
			int x,y;
			cin >> x >> y;
			arr[i] = {x,y};
		}
		vector<int>freq(n+1);
		vector<int>freq2(n+1);
		for(int i = 1; i<=n; i++){
			freq[arr[i].first]++;
			freq2[arr[i].second]++;
		}
		int ans = n*(n-1)*(n-2)/6;
		for(int i = 1; i<=n; i++){
			ans-=(freq[arr[i].first]-1)*(freq2[arr[i].second]-1);
		}
		cout << ans << "\n";
	}
	return 0;
}