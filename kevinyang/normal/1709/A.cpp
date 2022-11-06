#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int x;
		cin >> x;
		vector<int>a(4);
		for(int i = 1; i<=3; i++){
			cin >> a[i];
		}
		if(a[x]&&a[a[x]])cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}