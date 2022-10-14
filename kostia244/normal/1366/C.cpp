#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
const int maxn = 1<<17, mod = 1e9 + 7;
void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> cnt[2];
	cnt[0] = cnt[1] = vector<int>(n+m, 0);
	for(int i = 0; i < n; i++)
		for(int t, j = 0; j < m; j++) {
			cin >> t;
			cnt[t][min(i+j, n-i-1+m-j-1)]++;
		}
	int ans = 0;
	for(int i = 0; i < n+m; i++) if((n+m)%2 != 0 || i != (n+m-2)/2) ans += min(cnt[0][i], cnt[1][i]);
	cout << ans << '\n';
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}