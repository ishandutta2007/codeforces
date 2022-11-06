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
		vector<int>arr(n);
		for(int i = 0; i<n; i++){
			cin >> arr[i];
		}
		int mx = 0;
		int total = 0;
		for(int i = n-1; i>0; i--){
			mx = max(mx,arr[i]);
			if(mx>arr[i-1]){
				total+=mx-arr[i-1];
			}
		}
		if(k>total){
			cout << "-1\n";
			continue;
		}
		int ind = 0;
		for(int i = 0; i<k; i++){
			for(int j = 0; j<n-1; j++){
				if(arr[j]<arr[j+1]){
					arr[j]++;
					ind = j;
					break;
				}
			}
		}
		cout << ind+1 << "\n";
	}
	return 0;
}