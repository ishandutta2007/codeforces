#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int c[1009], p[1009], mn[99];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> c[i] >> s;
		for (int j = 0; j < s.length(); j++)
			p[i] += (1 << (s[j] - 'A'));
	}
	for (int i = 1; i < 8; i++) {
		mn[i] = 1000009;
		for (int j = 0; j < n; j++) 
			if ((p[j]&i) == i)
				mn[i] = min(mn[i], c[j]);
	}
	int ans = mn[7];
	for (int i = 1; i < 7; i++)
		ans = min(ans, mn[i] + mn[7 - i]);
	ans = min(ans, mn[1] + mn[2] + mn[4]);
	if (ans >= 1000009)
		cout << -1 << '\n';
	else
		cout << ans << '\n';
	return 0;
}