#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<vector<int>>arr(n,vector<int>(n));
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			cin >> arr[i][j];
		}
	}
	int v = 0;
	for(int j = 0; j<n; j++){
		v = __gcd(v,arr[0][j]);
	}
	for(int i = 1; i*i<=v; i++){
		if(v%i==0){
			vector<int>ans(n);
			ans[0] = i;
			for(int j = 1; j<n; j++){
				ans[j] = arr[0][j]/i;
			}
			bool f = true;
			for(int a = 0; a<n; a++){
				for(int b = a+1; b<n; b++){
					if(ans[a]*ans[b]==arr[a][b])continue;
					f = false;
				}
			}
			if(f){
				for(int j = 0; j<n; j++){
					cout << ans[j] << " ";
				}
				cout << "\n";
				return 0;
			}
		}
		if(v%i==0){
			vector<int>ans(n);
			ans[0] = v/i;
			for(int j = 1; j<n; j++){
				ans[j] = arr[0][j]/ans[0];
			}
			bool f = true;
			for(int a = 0; a<n; a++){
				for(int b = a+1; b<n; b++){
					if(ans[a]*ans[b]==arr[a][b])continue;
					f = false;
				}
			}
			if(f){
				for(int j = 0; j<n; j++){
					cout << ans[j] << " ";
				}
				cout << "\n";
				return 0;
			}
		}
	}
	return 0;
}