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
		vector<int> a(n);
		for(int i = 0; i < n; ++i){
			cin >> a[i];
		}
		int ans = 0;
		for(int i = 0; i < n; ++i){
			for(int j = i; j < min(n, i + 6); ++j){
				int f = 1;
				for(int x = i; x <= j; ++x){
					for(int y = x + 1; y <= j; ++y){
						for(int z = y + 1; z <= j; ++z){
							if(abs(a[z] - a[x]) == abs(a[y] - a[x]) + abs(a[z] - a[y])){
								f = 0;
								break;
							}
						}
						if(!f) break;
					}
					if(!f) break;
				}
				ans += f;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}