#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int r[2][2];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		string s; cin >> s;
		int n = s.length();
		int j = 0;
		r[0][0] = r[0][1] = r[1][0] = r[1][1] = 0;
		long long ans = 0;
		for (int i = 0; i < n; i++) {
			int rt = (i % 2);
			if (s[i] != '?')
				r[rt][(int)(s[i] - '0')]++;
			while (j <= i && (r[0][0] && r[0][1]) || (r[1][0] && r[1][1]) || (r[0][0] && r[1][0]) || (r[0][1] && r[1][1])) {
				if (s[j] != '?')
					r[(j % 2)][(int)(s[j] - '0')]--;
				j++;
			}
			ans += (i - j + 1);
		}
		cout << ans << '\n';
	}
	return 0;
}