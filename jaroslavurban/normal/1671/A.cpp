#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove() {
	string s; cin >> s;
	int n = s.size();
	int cnt = 1, pos = true;
	for (int i = 0; i < n - 1; ++i) if (s[i] != s[i + 1] && cnt == 1) pos = false;
	else if (s[i] != s[i + 1]) cnt = 1;
	else if (s[i] == s[i + 1]) ++cnt;
	if (cnt == 1) pos = false;
	cout << (pos ? "YES\n" : "NO\n");
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}