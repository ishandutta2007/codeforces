#include <bits/stdc++.h>
#define int long long
#define mi(x, y) (x = min(x, y))
#define ma(x, y) (x = max(x, y))
using namespace std;

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		int n, m, a, b, c, d; cin >> n >> m >> a >> b >> c >> d;
		int t = 0, da = 1, db = 1;
		while(a != c && b != d){
			++t;
			a += da, b += db;
			if(a > n){
				a -= 2; da = -1;
			}
			if(a < 1){
				a += 2; da = 1;
			}
			if(b > m){
				b -= 2; db = -1;
			}
			if(b < 1){
				b += 2; db = 1;
			}
		}
		cout << t << '\n';
	}
	return 0;
}