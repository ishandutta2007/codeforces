#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

string ans[1009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, l, k; string s;
	cin >> n >> l >> k >> s;
	sort(s.begin(), s.end());
	int ps = 0, pe = (int)s.length() - 1;
	for (int i = 0; i < l; i++)
		for (int j = 0; j < n; j++) {
			if (j < k && (i == 0 || ans[j][i - 1] == ans[k - 1][i - 1])) { ans[j] += s[ps]; ps++; }
			else { ans[j] += s[pe]; pe--; }
		}
	sort(ans, ans + n);
	for (int i = 0; i < n; i++)
		cout << ans[i] << '\n';
	return 0;
}