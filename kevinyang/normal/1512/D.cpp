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
		vector<int>arr(n+3);
		for(int i = 1; i<=n+2; i++){
			cin >> arr[i];
		}
		vector<int>psa(n+3);
		sort(arr.begin(),arr.end());
		for(int i = 1; i<=n+2; i++){
			psa[i] = psa[i-1]+arr[i];
		}
		if(psa[n]==arr[n+1]){
			for(int i = 1; i<=n; i++){
				cout << arr[i] << " ";
			}
			cout << "\n";
			continue;
		}
		bool f = false;
		for(int i = 1; i<=n+1; i++){
			if(psa[n+1]-arr[i]==arr[n+2]){
				for(int j = 1; j<=n+1; j++){
					if(j==i)continue;
					cout << arr[j] << " ";
				}
				cout << "\n";
				f = true;
			}
			if(f) break;
		}
		if(f)continue;
		cout << "-1\n";
	}
	return 0;
}