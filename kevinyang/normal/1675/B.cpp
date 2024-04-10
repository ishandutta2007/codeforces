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
		vector<int>arr(n+1);
		for(int i = 1; i<=n; i++){
			cin >> arr[i];
		}
		int cnt = 0;
		for(int i = n-1; i>=1; i--){
			while(arr[i]!=0&&arr[i]>=arr[i+1]){
				cnt++;
				arr[i]/=2;
			}
		}
		bool f = true;
		for(int i = 1; i<n; i++){
			if(arr[i]>=arr[i+1])f = false;
		}
		if(f)cout << cnt << "\n";
		else cout << "-1\n";
	}
	return 0;
}