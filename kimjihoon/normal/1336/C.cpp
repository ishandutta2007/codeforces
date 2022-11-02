#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int d[3009][3009];
long long md = 998244353;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s, t; cin >> s >> t;
	int m = t.length();
	for (int i = 0; s.length() != t.length(); i++)
		t += '?';
	for (int i = 0; i < s.length(); i++) {
		if (t[i] == '?' || t[i] == s[0]) d[i][i] = 2;
	}
	for (int i = 1; i < (int)s.length(); i++) {
		for (int j = 0; j < (int)s.length() - i; j++) {
			int l = j, r = i + j;
			if (s[r - l] == t[l] || t[l] == '?') d[l][r] += d[l + 1][r];
			if (s[r - l] == t[r] || t[r] == '?') d[l][r] += d[l][r - 1];
			d[l][r] = d[l][r] % md;		
		}
	}
	long long ans = 0;
	for (int i = m - 1; i < s.length(); i++)
		ans = (ans + d[0][i]) % md;
	cout << ans << '\n';
	return 0;
}