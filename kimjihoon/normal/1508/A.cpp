#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int p[3];
string s[3];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		for (int i = 0; i < 3; i++) {
			cin >> s[i];
			p[i] = 0;
			for (int j = 0; j < 2 * n; j++)
				if (s[i][j] == '1')
					p[i]++;
			if (p[i] >= n) p[i] = 1;
			else p[i] = 0;
		}
		int a = 0, b = 1;
		if (p[a] != p[b]) b = 2;
		if (p[a] != p[b]) a = 1;
		string ans = "";
		int c = 0, ai = 0, bi = 0;
		char cc = (char)(p[a] + '0');
		for (int i = 0; i < 3 * n; i++) {
			if (c < n && s[a][ai] == cc && s[b][bi] == cc) {
				ans += cc;
				ai++; bi++;
				c++;
			}
			else if (ai < 2 * n && (c >= n || s[a][ai] != cc)) {
				ans += s[a][ai];
				ai++;
			}
			else {
				ans += s[b][bi];
				bi++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}