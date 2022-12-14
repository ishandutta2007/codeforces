#include <bits/stdc++.h>
#define int long long
#define umi(x, y) (x = min(x, y))
#define uma(x, y) (x = max(x, y))
using namespace std;

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		if(n <= 26){
			for(int i = 0; i < n; ++i){
				cout << (char)(i + 'a');
			}
			cout << '\n';
			continue;
		}
		int m;
		if(n % 2) m = n - 2;
		else m = n - 1;
		for(int i = 0; i < m / 2; ++i) cout << 'a';
		if(n % 2) cout << "bc";
		else cout << "b";
		for(int i = 0; i < m / 2 + 1; ++i) cout << 'a';
		cout << '\n';
	}
	return 0;
}