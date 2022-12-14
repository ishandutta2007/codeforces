#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		if(n == 2){
			cout << "-1\n";
			continue;
		}
		int cnt = 1;
		for(int i = 1; i <= n; ++i){
			if(i % 2){
				for(int j = 1; j <= n; ++j){
					if(j % 2){
						cout << (cnt++) << ' ';
					}
					else{
						cout << ((n * n + 1) / 2 + cnt - 1) << ' ';
					}
				}
				cout << '\n';
			}
			else{
				for(int j = 1; j <= n; ++j){
					if(j % 2 == 0){
						cout << (cnt++) << ' ';
					}
					else{
						cout << ((n * n + 1) / 2 + cnt - 1 + (n % 2 == 0)) << ' ';
					}
				}
				cout << '\n';
			}
		}
	}
	return 0;
}