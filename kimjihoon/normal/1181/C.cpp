#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s[1009];
int rs[1009][1009], ls[1009][1009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		for (int j = 0; j < m; j++) {
			if (i == 0 || s[i][j] != s[i - 1][j]) rs[i][j] = 1;
			else rs[i][j] = rs[i - 1][j] + 1;
			if (j == 0 || s[i][j] != s[i][j - 1]) ls[i][j] = 1;
			else ls[i][j] = ls[i][j - 1] + 1;
		}
	}
	for (int i = n - 2; i >= 0; i--)
		for (int j = 0; j < m; j++)
			if (s[i][j] == s[i + 1][j]) rs[i][j] = rs[i + 1][j];
	long long ans = 0;
	for (int j = 0; j < m; j++) {
		int um, dm, hm;
		for (int i = 0; i < n; i++) {
			if (i == 0 || s[i][j] != s[i - 1][j]) {
				um = dm = hm = 1000000000;
				if (i != 0 && rs[i - 1][j] >= rs[i][j]) 
					for (int k = i - rs[i][j]; k < i; k++)
						um = min(um, ls[k][j]);
			}
			hm = min(hm, ls[i][j]);
			if (um != 1000000000 && i != n - 1 && s[i][j] != s[i + 1][j] && rs[i + 1][j] >= rs[i][j]) {
				for (int k = i + 1; k <= i + rs[i][j]; k++)
					dm = min(dm, ls[k][j]);
				ans += min(hm, min(dm, um));
			}
		}
	}
	cout << ans << '\n';
	return 0;
}