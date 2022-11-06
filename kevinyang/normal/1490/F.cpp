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
		vector<int>arr(n);
		vector<int>sorted;
		for(int i = 0; i<n; i++){
			cin >> arr[i];
			sorted.push_back(arr[i]);
		}
		sort(sorted.begin(),sorted.end());
		for(int i = 0; i<n; i++){
			int ind = lower_bound(sorted.begin(),sorted.end(),arr[i])-sorted.begin();
			arr[i] = ind;
		}
		vector<int>freq(n+1);
		for(int i = 0; i<n; i++){
			freq[arr[i]]++;
		}
		sort(freq.begin(),freq.end());
		vector<int>psa(n+1);
		for(int i = 1; i<=n; i++){
			psa[i] = psa[i-1]+freq[i];
		}
		int ans = (int)1e18;
		for(int i = 1; i<=*(--freq.end()); i++){
			int ind = lower_bound(freq.begin(),freq.end(),i)-freq.begin();
			ans = min(ans,psa[n]-i*(n-ind+1));
		}
		cout << ans << "\n";
	}
	return 0;
}