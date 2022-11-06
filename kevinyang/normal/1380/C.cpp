#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,x;
		cin >> n >> x;
		vector<int>arr(n);
		for(int i = 0; i<n; i++){
			cin >> arr[i];
		}
		sort(arr.begin(), arr.end());
		int cur = 0;
		int count = 0;
		for(int i = n-1; i>=0; i--){
			cur++;
			if(cur*arr[i]>=x){
				count++;
				cur = 0;
			}
		}
		cout << count << "\n";
	}
	return 0;
}