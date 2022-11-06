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
		for(int i = 0; i<n; i++){
			cin >> arr[i];
		}
		int ans = 0;
		for(int i = 0; i<n-3; i++){
			vector<int>freq1(3001);
			vector<int>freq2(3001);
			for(int j = i+2; j<n; j++){
				freq2[arr[j]]++;
			}
			int cur = 0;
			for(int j = i+2; j<n-1; j++){
				freq1[arr[j-1]]++;
				cur+=freq2[arr[j-1]];
				freq2[arr[j]]--;
				cur-=freq1[arr[j]];
				if(arr[i]==arr[j]){
					ans+=cur;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}