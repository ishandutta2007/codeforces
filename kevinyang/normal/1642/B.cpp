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
		set<int>s;
		for(int i = 0; i<n; i++){
			int x;
			cin >> x;
			s.insert(x);
		}
		for(int i = 1; i<=n; i++){
			cout << max((int)s.size(),i) << " ";
		}
		cout << "\n";
	}
	return 0;
}