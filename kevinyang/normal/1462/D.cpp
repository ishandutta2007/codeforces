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
		for(int i = 0; i<n; i++){
			int sum = 0;
			for(int j = 0; j<=i; j++){
				sum+=arr[j];
			}
			int count = 1;
			int cur = 0;
			bool f = true;
			for(int j = i+1; j<n; j++){
				cur+=arr[j];
				if(cur>sum){
					f = false;
				}
				if(cur==sum){
					count++;
					cur = 0;
				}
			}
			if(cur>0)f = false;
			if(!f){
				continue;
			}
			cout << n-count << "\n";
			break;
		}
	}
	return 0;
}