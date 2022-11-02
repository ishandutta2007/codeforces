#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int p[3000009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		string ts, s = ""; cin >> ts;
		s += ts[0];
		for (int i = 1; i < ts.length(); i++) {
			s += ".";
			s += ts[i];
		}
		int n = s.length();
		int c = 0;
		while (c < n - c - 1 && s[c] == s[n - c - 1]) c++;
		int r = -1, rp = -1;
		int mx = 0, ap = 0;
		for (int i = 0; i < n; i++) {
			p[i] = 0;
			if (i <= r) p[i] = min(r - i, p[rp * 2 - i]);
			while (0 <= i - p[i] - 1 && i + p[i] + 1 < n && s[i - p[i] - 1] == s[i + p[i] + 1]) p[i]++;
			if (r < i + p[i]) {
				r = i + p[i]; rp = i;
			}
			if (c <= i && i <= n - c - 1 && mx < min(p[i] + 1, min(i - c + 1, n - c - i)) && (i - p[i] <= c || i + p[i] >= n - c - 1)) {
				mx = min(p[i] + 1, min(i - c + 1, n - c - i));
				ap = i;
			}
		}
		for (int i = 0; i < c; i++)
			if (s[i] != '.') cout << s[i];
		for (int i = ap - mx + 1; i <= ap + mx - 1; i++)
			if (s[i] != '.') cout << s[i];
		for (int i = c - 1; i >= 0; i--)
			if (s[i] != '.') cout << s[n - i - 1];
		cout << '\n';
	}
	return 0;
}