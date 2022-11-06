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
		int sum = 0;
		for(int i = 0; i<n; i++){
			int x;
			cin >> x;
			sum+=x;
		}
		if(sum==m)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}