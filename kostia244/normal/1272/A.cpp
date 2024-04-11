#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
void solve() {
	vi x;
	x.resize(3);
	for(auto &i : x) cin >> i;
	sort(all(x));
	ll ans = LLONG_MAX;
	for(int i = 0; i < 3*3*3; i++) {
		for(int t = i, j = 0; j < 3; j++, t/=3) {
			x[j] += (t%3)-1;
		}
		ans = min(abs(x[0]-x[1]) + abs(x[1]-x[2]) + abs(x[2]-x[0]), ans);
		for(int t = i, j = 0; j < 3; j++, t/=3) {
			x[j] -= (t%3)-1;
		}
	}
	cout << ans << "\n";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
}