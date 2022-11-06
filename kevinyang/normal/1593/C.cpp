#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		vector<int>arr(k+1);
		for(int i = 1; i<=k; i++){
			cin >> arr[i];
		}
		sort(arr.begin(),arr.end());
		int low = 0; int high = k; int mid = (low+high)/2;
		while(low+1<high){
			int sum = 0;
			for(int i = mid; i<=k; i++){
				sum+=n-arr[i];
			}
			if(sum<n)high = mid;
			else low = mid;
			mid = (low+high)/2;
		}
		cout << k-high+1 << "\n";
	}
	return 0;
}