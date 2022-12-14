#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	vector<vector<int>> a(n + 1, vector<int>(n + 1));
	int all = 0;
	auto out = [&](int x, int i, int j){
		cout << x << ' ' << i << ' ' << j << '\n';
		a[i][j] = x;
		cout.flush();
	};
	auto sol = [&](int k, int we){
		int f = 1;
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= n; ++j){
				if(!a[i][j]){
					int x;
					if(!f){
						cin >> x;
					}
					else{
						x = k;
					}
					f = 0;
					if(x != 3) out(3, i, j);
					else out(we, i, j);
				}
			}
		}
	};
	for(int k = 1; k <= n * n; ++k){
		int x; cin >> x;
		if(x != 1){
			int f = 1;
			for(int i = 1; i <= n; ++i){
				for(int j = 1; j <= n; ++j){
					if((i + j) % 2){
						if(!a[i][j] && f){
							f = 0;
							out(1, i, j);
							break;
						}
					}
				}
			}
			if(f){
				sol(x, 2);
				return 0;
			}
		}
		else if(x != 2){
			int f = 1;
			for(int i = 1; i <= n; ++i){
				for(int j = 1; j <= n; ++j){
					if((i + j) % 2 == 0){
						if(!a[i][j] && f){
							f = 0;
							out(2, i, j);
							break;
						}
					}
				}
			}
			if(f){
				sol(x, 1);
				return 0;
			}
		}
	}
	return 0;
}