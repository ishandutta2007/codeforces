#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

long long p[29][29], c[29];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s; cin >> s;
	long long ans = 0;
	for (int i = 0; i < s.length(); i++) {
		int t = s[i] - 'a';
		for (int j = 0; j < 26; j++)
			p[j][t] += c[j];
		c[t]++;
		ans = max(ans, c[t]);
	}
	for (int i = 0; i < 26; i++)
		for (int j = 0; j < 26; j++)
			ans = max(ans, p[i][j]);
	cout << ans << '\n';
	return 0;
}