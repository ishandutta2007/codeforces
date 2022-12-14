#include <bits/stdc++.h>
#define int long long
#define mi(x, y) (x = min(x, y))
#define ma(x, y) (x = max(x, y))
using namespace std;

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	vector<int> a(n), r(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	map<int, int> lst;
	for(int i = n - 1; i >= 0; --i){
		r[i] = lst[a[i]];
		if(!lst[a[i]]) lst[a[i]] = i;
	}
	int ans = 0;
	for(int i = 0; i < n; ++i){
		if(!r[i]){
			continue;
		}
		int e = r[i], lst = i + 1, cnt = 1;
		while(true){
			int mx = -1;
			for(int j = lst; j <= e; ++j){
				ma(mx, r[j]);
			}
			if(mx > e){
				++cnt; lst = e + 1;
				e = mx;
			}
			else{
				break;
			}
		}
		ans += (e - i + 1) - cnt - 1;
		i = e;
	}
	cout << ans << '\n';
	return 0;
}