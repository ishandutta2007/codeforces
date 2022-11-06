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
		bool f = true;
		int odd = 0; int even = 0;
		for(int i = 1; i<=n; i++){
			if(arr[i]%2==1){
				odd = max(odd,arr[i]);
				if(odd>arr[i]){
					f = false;
				}
			}
			else{
				even = max(even,arr[i]);
				if(even>arr[i]){
					f = false;
				}
			}
		}
		if(f)cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}