#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n, a, b, c; cin >> n >> a >> b >> c;
		string s; cin >> s;
		string ans = ""; int ac = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == 'S' && a > 0) { a--; ac++; ans += "R"; }
			else if (s[i] == 'R' && b > 0) { b--; ac++; ans += "P"; }
			else if (s[i] == 'P' && c > 0) { c--; ac++; ans += "S"; }
			else ans += " ";
		}
		for (int i = 0; i < n; i++) {
			if (ans[i] != ' ') continue;
			if (a > 0) { a--; ans[i] = 'R'; }
			else if (b > 0) { b--; ans[i] = 'P'; }
			else if (c > 0) { c--; ans[i] = 'S'; }
		}
		if (ac * 2 < n) cout << "NO" << '\n';
		else {
			cout << "YES" << '\n';
			cout << ans << '\n';
		}
	}
	return 0;
}