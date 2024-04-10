#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

// views::zip, ranges::sort

typedef long long ll;
typedef long double ld;

void ProGamerMove() {
	int n; cin >> n;
	string s; cin >> s;
	if (int cnt = count(s.begin(), s.end(), '1'); cnt == 0 || (cnt & 1)) { cout << "NO\n"; return; }
	cout << "YES\n";
	auto it = find(s.begin(), s.end(), '1');
	int shift = it - s.begin();
	rotate(s.begin(), it, s.end());
	vector<int> ends;
	vector<pair<int, int>> res;
	for (int i = 0; i < n; ++i) if (s[i] == '1') ends.push_back(i - 1);
	else res.push_back({i - 1, i});
	assert(!(ends.size() & 1));
	for (int i = 1; i < ends.size(); ++i) res.push_back({ends[0], ends[i]});
	assert(res.size() == n - 1);
	auto norm = [&] (int u) { return ((u % n) + n + shift) % n + 1; };
	for (auto [u, v] : res) cout << norm(u) << ' ' << norm(v) << '\n';
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}