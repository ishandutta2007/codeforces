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
		int n, m; cin >> n >> m;
		vector<vector<int>> a(m, vector<int>(3));
		for(int i = 0; i < m; ++i){
			cin >> a[i][0] >> a[i][1];
			a[i][2] = i;
		}
		vector<vector<int>> srt(m);
		n *= 2;
		for(int i = 0; i < m; ++i){
			srt[i] = {a[i][1], a[i][0], a[i][2]};
		}
		sort(srt.begin(), srt.end());
		int ans = 0;
		vector<vector<int>> out;
		for(int i = 0; i < n / 2; ++i){
			ans += srt[i][0];
			ans += srt[n - i - 1][0];
			out.push_back({srt[i][1], srt[i][2]});
			out.push_back({srt[n - i - 1][1], srt[n - i - 1][2]});
		}
		sort(out.begin(), out.end());
		cout << ans << '\n';
		for(int i = 0; i < n / 2; ++i){
			cout << out[i][1] + 1 << ' ' << out[n - i - 1][1] + 1 << '\n';
		}
		cout << '\n';
	}
	return 0;
}