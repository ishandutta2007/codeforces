#include <bits/stdc++.h>
#define int long long
#define mi(x, y) (x = min(x, y))
#define ma(x, y) (x = max(x, y))
using namespace std;

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n; cin >> n;
		string a, b; cin >> a >> b;
		int same = 0, diff = 0;
		for(int i = 0; i < n; ++i){
			if(a[i] == b[i]) ++same;
			else ++diff;
		}
		int ans = (int)1e9;
		if(same % 2){
			int  x = 0;
			for(int i = 0; i < n; ++i){
				if(a[i] == b[i]){
					if(a[i] == '1') ++x;
					else --x;
				}
			}
			if(x == 0 || x == 1) ans = min(ans, same);
		}
		if(diff % 2 == 0){
			int  x = 0;
			for(int i = 0; i < n; ++i){
				if(a[i] != b[i]){
					if(a[i] == '1') ++x;
					else --x;
				}
			}
			if(x == 0 || x == 1) ans = min(ans, diff);
		}
		if(ans == (int)1e9) ans = -1;
		cout << ans << '\n';
	}
	return 0;
}