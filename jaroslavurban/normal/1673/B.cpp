#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

// views::zip, ranges::sort

typedef long long ll;
typedef long double ld;

void ProGamerMove() {
	string s; cin >> s;
	int n = s.size();
	map<char, int> pos;
	for (auto c : s) pos[c] = 0;
	int m = pos.size();
	for (int i = 0; i < n; ++i) pos[s[i]] = i % m;
	for (int i = 0; i < n; ++i) if (pos[s[i]] != i % m) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}