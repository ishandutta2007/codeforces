#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		string s; cin >> s;
		int ans = n;
		bool f0 = false, f1 = false;
		for (int i = 0; i < n; i++) {
			if (s[i] != '-' && s[(i + 1) % n] != '-') ans--;
			if (s[i] == '<') f0 = true;
			if (s[i] == '>') f1 = true;
		}
		if (f0 && f1) cout << ans << '\n';
		else cout << n << '\n';
	}
	return 0;
}