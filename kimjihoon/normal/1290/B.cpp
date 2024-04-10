#include <iostream>
#include <string>
using namespace std;

int sp[200009][26];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s; cin >> s;
	for (int i = 0; i < s.length(); i++) {
		for (int j = 0; j < 26; j++)
			sp[i + 1][j] = sp[i][j];
		sp[i + 1][s[i] - 'a']++;
	}
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		int l, r; cin >> l >> r;
		if (l == r || s[l - 1] != s[r - 1]) cout << "Yes" << '\n';
		else {
			int c = 0;
			for (int j = 0; j < 26; j++)
				if (sp[r][j] - sp[l - 1][j] > 0)
					c++;
			if (c >= 3) cout << "Yes" << '\n';
			else cout << "No" << '\n';
		}
	}
	return 0;
}