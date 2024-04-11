#include <bits/stdc++.h>
using namespace std;

#define FOR(i, b, e) for(int i = (b); i < (e); i++)
using vi = vector<int>;

void solve() {
	int n;
	vi vec(10, -1000);
	cin >> n;
	FOR(i, 0, n) {
		int b, d;
		cin >> b >> d;
		vec[d-1] = max(vec[d-1], b);
	}
	int sum = 0;
	FOR(i, 0, 10) sum += vec[i];
	if(sum < 0) cout << "MOREPROBLEMS\n";
	else cout << sum << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt; cin >> tt;
	FOR(te, 0, tt) solve();
	return 0;
}