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
		vector<int> a(n), b(n);
		for(int i = 0; i < n; ++i){
			cin >> a[i];
		}
		for(int i = 0; i < n; ++i){
			cin >> b[i];
		}
		int suma = 0, sumb = 0, ans = (int)1e18;
		for(int i = n - 1; i >= 1; --i){
			suma += a[i];
		}
		for(int i = 0; i < n; ++i){
			ans = min(ans, max(suma, sumb));
			if(i == n - 1) break;
			suma -= a[i + 1];
			sumb += b[i];
		}
		cout << ans << '\n';
	}
	return 0;
}