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
		vector<vector<int>>arr(n,vector<int>(n));
		for(int i = 0; i<n; i++){
			string s;
			cin >> s;
			for(int j = 0; j<n; j++){
				arr[i][j] = s[j]-'0';
			}
		}
		for(int i = 0; i<n; i++){
			string s;
			cin >> s;
			for(int j = 0; j<n; j++){
				arr[i][j]^=(s[j]-'0');
			}
		}
		for(int i = 0; i<n; i++){
			if(arr[i][0]){
				for(int j = 0; j<n; j++){
					arr[i][j]^=1;
				}
			}
		}
		bool f = true;
		for(int i = 0; i<n; i++){
			int sum = 0;
			for(int j = 0; j<n; j++){
				sum+=arr[j][i];
			}
			if(sum==0||sum==n)continue;
			f = false;
		}
		if(f){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
	return 0;
}