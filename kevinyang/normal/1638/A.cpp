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
		for(int i = 1; i<=n; i++){
			if(arr[i]!=i){
				int idx = 0;
				for(int j = i; j<=n; j++){
					if(arr[j]==i){
						idx = j;
						break;
					}
				}
				reverse(arr.begin()+i,arr.begin()+idx+1);
				break;
			}
		}
		for(int i = 1; i<=n; i++){
			cout << arr[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}