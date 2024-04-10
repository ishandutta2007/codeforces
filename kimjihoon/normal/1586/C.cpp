#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string s[1000009];
int c[1000009], ss[1000009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	for (int i = 1; i < n; i++)
		for (int j = 1; j < m; j++)
			if (s[i - 1][j] == 'X' && s[i][j - 1] == 'X')
				c[j] = 1;
	ss[0] = c[0];
	for (int i = 1; i < m; i++)
		ss[i] = ss[i - 1] + c[i];
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		int l, r; cin >> l >> r;
		if (ss[r - 1] - ss[l - 1] > 0) cout << "NO" << '\n';
		else cout << "YES" << '\n';
	}
	return 0;
}