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
		map<string,int>hm;
		vector<string>arr(n);
		for(int i = 0; i<n; i++){
			cin >> arr[i];
			hm[arr[i]] = 1;
		}
		for(int i = 0; i<n; i++){
			bool f = false;
			for(int j = 1; j<arr[i].size(); j++){
				if(hm[arr[i].substr(0,j)]&&hm[arr[i].substr(j)]){
					f = true;
				}
			}
			if(f)cout << 1;
			else cout << 0;
		}
		cout << "\n";
	}
	return 0;
}