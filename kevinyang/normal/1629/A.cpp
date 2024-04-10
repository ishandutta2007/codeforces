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
		vector<pair<int,int>>arr(n);
		for(int i = 0; i<n; i++){
			cin >> arr[i].first;
		}
		for(int i = 0; i<n; i++){
			cin >> arr[i].second;
		}
		sort(arr.begin(),arr.end());
		
		for(int i = 0; i<n; i++){
			if(k>=arr[i].first){
				k+=arr[i].second;
			}
			else{
				break;
			}
		}
		cout << k << "\n";
	}
	return 0;
}