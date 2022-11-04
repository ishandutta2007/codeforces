#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove() {
	string s; cin >> s;
	set<char> got;
	int n = s.size();
	reverse(s.begin(), s.end());
	int mx = 0;
	for (int i = 0; i < n; ++i) {
		if (!got.count(s[i])) mx = i;
		got.insert(s[i]);
	}
	s.erase(s.begin() + mx + 1, s.end());
	reverse(s.begin(), s.end());
	cout << s << "\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}