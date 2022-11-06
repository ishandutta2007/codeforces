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
		int mx = 0;
		sort(arr.begin(),arr.end());
		for(int i = 2; i<=100; i++){
			int count = 0;
			int left = 0;
			int right = n-1;
			while(left<right){
				if(arr[left]+arr[right]==i){
					count++;
					left++; right--;
				}
				else if(arr[left]+arr[right]>i){
					right--;
				}
				else{
					left++;
				}
			}
			mx = max(mx,count);
		}
		cout << mx << "\n";
	}
	return 0;
}