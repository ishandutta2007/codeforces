#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int c[10009];
string s[19];

int sti(string s)
{
	int p = 0;
	for (int i = 0; i < s.length(); i++)
		p = p * 10 + s[i] - '0';
	return p;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); 
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		for (int i = 0; i < 10000; i++)
			c[i] = 0;
		for (int i = 0; i < n; i++) {
			cin >> s[i];
			c[sti(s[i])]++;
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (c[sti(s[i])] > 1) {
				c[sti(s[i])]--;
				ans++;
				string ts = s[i];
				for (int j = 0; j < 4; j++) {
					for (int k = '0'; k <= '9'; k++) {
						ts[j] = k;
						if (!c[sti(ts)]) break;
					}
					if (!c[sti(ts)]) break;
					ts = s[i];
				}
				s[i] = ts;
			}
			c[sti(s[i])]++;
		}
		cout << ans << '\n';
		for (int i = 0; i < n; i++)
			cout << s[i] << '\n';
	}
	return 0;
}