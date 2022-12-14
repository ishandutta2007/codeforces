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
		int n, k; cin >> n >> k;
		if(k * 2 - 1 <= n){
			for(int i = 1; i <= n; ++i){
				for(int j = 1; j <= n; ++j){
					if(i % 2 == 0 || i != j || i / 2 + 1 > k){
						cout << '.';
					}
					else cout << 'R';
				}
				cout << '\n';
			}
		}
		else{
			cout << "-1\n";
		}
	}
	return 0;
}