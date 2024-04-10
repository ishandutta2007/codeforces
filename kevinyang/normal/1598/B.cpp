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
		vector<vector<int>>arr(5,vector<int>(n));
		for(int i = 0; i<n; i++){
			for(int j = 0; j<5; j++){
				cin >> arr[j][i];
			}
		}
		bool ans = false;
		for(int a = 0; a<5; a++){
			for(int b = a+1; b<5; b++){
				int c1 = 0;
				int c2 = 0;
				bool f = false;
				for(int i = 0; i<n; i++){
					if(arr[a][i]==0&&arr[b][i]==0)f = true;
					c1+=arr[a][i]; c2+=arr[b][i];
				}
				if(c1<n/2||c2<n/2||f)continue;
				ans = true;
			}
		}
		if(ans)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}