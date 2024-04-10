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
		string x, y; cin >> x >> y;
		int pos = (int)x.size() - 1, f = 1;
		for(int i = (int)y.size() - 1; i >= 0; --i){
			while(pos >= 0 && x[pos] != y[i]) pos -= 2;
			if(pos < 0){
				f = 0; break;
			}
			--pos;
		}
		if(f) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}