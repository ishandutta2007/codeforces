//#pragma GCC optimize("trapv")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
const int maxn = 125, mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
	string s;
	cin >> s;
	int lst = -1, ans = 0;
	for(int i = 0; i < s.size(); i++) {
		if(s[i]=='R') ans = max(ans, i-lst), lst = i;
	}
	ans = max(ans, (int)s.size()-lst);
	cout << ans << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
}