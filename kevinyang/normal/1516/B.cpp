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
		int sum = 0;
		vector<int>arr(n+1);
		for(int i = 1; i<=n; i++){
			cin >> arr[i]; sum^=arr[i];
		}
		vector<int>pre(n+1); vector<int>suf(n+5);
		for(int i = 1; i<=n; i++){
			pre[i] = pre[i-1]^arr[i];
		}
		for(int i = n; i>=1; i--){
			suf[i] = suf[i+1]^arr[i];
		}
		bool f = false;
		for(int i = 1; i<n; i++){
			if(pre[i]==suf[i+1])f = true;
		}
		for(int i = 1; i<n; i++){
			for(int j = i+2; j<=n; j++){
				if((pre[j-1]^pre[i])==pre[i]&&pre[i]==suf[j])f = true;
			}
		}
		if(f)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}