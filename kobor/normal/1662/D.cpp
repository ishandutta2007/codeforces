#include <bits/stdc++.h>
using namespace std;

#define FOR(i, b, e) for(int i = (b); i < (e); i++)
#define SZ(x) ((int)x.size())
using vi = vector<int>;

string unify(string s) {
	string ans;
	int xol = 0;
	for(auto &x: s) {
		if(x == 'B') {
			xol ^= 1;
			continue;
		}
		ans += x;
		int ind = SZ(ans) - 1;
		while(ind > 0 && ans[ind] < ans[ind - 1]) {
			if(ans[ind] == 'A' && ans[ind - 1] == 'C') break;
			swap(ans[ind], ans[ind - 1]);
			ind--;
		}
		if(ind > 0 && ans[ind - 1] == ans[ind]) {
			ans = ans.substr(0, ind - 1) + ans.substr(ind + 1);
		}
	}
	return ans + (xol ? "B" : "");
}

void solve() {
	string a, b;
	cin >> a >> b;
	cout << (unify(a) == unify(b) ? "YES\n" : "NO\n");
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt; cin >> tt;
	FOR(te, 0, tt) solve();
	return 0;
}