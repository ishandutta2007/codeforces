#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int>arr(n+1);
	int mx = 0;
	for(int i = 1; i<=n; i++){
		cin >> arr[i];
		mx = max(mx,arr[i]);
	}
	bool flag = false;
	for(int i = 1; i<=n; i++){
		arr[i] = (mx-arr[i])%2;
	}
	if(true){
		int odd = 0;
		int even = 0;
		for(int i = 1; i<=n; i++){
			if(i%2)odd+=arr[i];
			else even+=arr[i];
		}
		if(odd==even)flag = true;
		for(int i = 1; i<=n; i++){
			arr[i]^=1;
		}
	}
	if(true){
		int odd = 0;
		int even = 0;
		for(int i = 1; i<=n; i++){
			if(i%2)odd+=arr[i];
			else even+=arr[i];
		}
		if(odd==even)flag = true;
		for(int i = 1; i<=n; i++){
			arr[i]^=1;
		}
	}	
	if(flag)cout << "YES\n";
	else cout << "NO\n";
	return 0;
}