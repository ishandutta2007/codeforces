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
		vector<int>pre(n+1);
		for(int i = 1; i<=n; i++){
			pre[i] = max(pre[i-1],arr[i]);
		}
		int cnt = 0;
		for(int i = 1; i<=n; i++){
			if(pre[i]==i)cnt++;
		}
		cout << cnt << "\n";
	}
	return 0;
}