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
		for(int i = 1; i<=n; i++){
			if(arr[i]<0)cnt++;
		}
		for(int i = 1; i<=cnt; i++){
			arr[i] = abs(arr[i])*-1;
		}
		for(int i = cnt+1; i<=n; i++){
			arr[i] = abs(arr[i]);
		}
		bool f = true;
		for(int i = 2; i<=n; i++){
			if(arr[i]<arr[i-1]){
				f = false;
			}
		}
		cout << (f?"YES":"NO") << "\n";
	}
	return 0;
}