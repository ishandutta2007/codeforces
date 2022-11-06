#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		vector<char>arr(m);
		for(int i = 0; i<2*n-1; i++){
			string s;
			cin >> s;
			for(int j = 0; j<m; j++){
				arr[j]^=s[j];
			}
		}
		for(int j = 0; j<m; j++){
			cout << (char)arr[j];
		}
		cout << "\n";
	}
	return 0;
}