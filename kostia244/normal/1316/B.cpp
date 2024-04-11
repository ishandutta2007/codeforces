#define dominance 1
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
const int maxn = 2e6 + 55;//, mod = 1e9 + 7;
string apply(string s, int k) {
	string res;
	for(int i = k-1;i < s.size(); i++)
		res += s[i];
	if(((int)s.size()-k+1)&1) {
		for(int i = k-1; i--;)
			res += s[i];
	} else {
		for(int i = 0; i < k-1; i++)
			res += s[i];
	}
	return res;
}
void solve() {
	int n;
	string s;
	cin >> n >> s;
	pair<string, int> ans = {s, 1};
	for(int i = 1; i <= n; i++) {
		ans = min(ans, {apply(s, i), i});
	}
	cout << ans.first << '\n' << ans.second << '\n';
}
int main() {
	assert(dominance);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
}