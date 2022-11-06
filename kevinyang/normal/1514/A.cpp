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
		bool f = true;
		for(int i = 0; i<n; i++){
			int x;
			cin >> x;
			if((int)sqrt(x)*(int)sqrt(x)!=x)f = false;
		}
		if(f)cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}