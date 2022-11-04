#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

// views::zip, ranges::sort

typedef long long ll;
typedef long double ld;

string red(string s) {
	string res;
	if (count(s.begin(), s.end(), 'B') & 1) res += "B";
	for (int i = 0; i < s.size(); ++i) if (s[i] == 'A' || s[i] == 'C') {
		if (res.size() && res.back() == s[i]) res.pop_back();
		else res += s[i];
	}
	return res;
}

void ProGamerMove() {
	string s, t; cin >> s >> t;
	cout << (red(s) == red(t) ? "YES\n" : "NO\n");
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}