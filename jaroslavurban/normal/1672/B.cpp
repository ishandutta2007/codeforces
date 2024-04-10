#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove() {
	string s; cin >> s;
	int n = s.size();
	bool pos = (s[0] == 'A') && (s[n - 1] == 'B');
	int cnt = 0;
	while (pos && s.size()) {
		if (s.back() == 'B') ++cnt;
		else cnt = max(0, cnt - 1);
		s.pop_back();
	}
	cout << (pos && !cnt ? "YES\n" : "NO\n");
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}