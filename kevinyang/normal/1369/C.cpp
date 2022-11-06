#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		vector<int>arr(n);
		for(int i = 0; i<n; i++){
			cin >> arr[i];
		}
		vector<int>friends(k);
		for(int i = 0; i<k; i++){
			cin >> friends[i];
		}
		sort(arr.begin(), arr.end());
		reverse(arr.begin(), arr.end());
		sort(friends.begin(), friends.end());
		int index = 0;
		long long ans = 0;
		int start = 0;
		for(; index<k; index++){
			ans+=arr[index];
			friends[index]--;
			if(friends[index]==0){
				start++;
				ans+=arr[index];
			}
		}
		for(int i = 0; i<k; i++){
			for(int j = 0; j<friends[i]; j++){
				if(j==friends[i]-1){
					ans+=arr[index];
				}
				index++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}