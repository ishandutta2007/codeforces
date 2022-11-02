#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int p[1000009], M = 500000;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		int mn = 0, t = 0;
		for (int j = 0; j < s.length(); j++) {
			if (s[j] == '(') t++;
			else t--;
			mn = min(mn, t);
		}
		if ((t >= 0 && mn >= 0) || (t < 0 && mn >= t))
			p[t + M]++;
	}
	int ans = 0;
	for (int i = 0; i < M; i++)
		ans += min(p[i], p[2 * M - i]);
	ans += p[M] / 2;
	cout << ans << '\n';
	return 0;
}