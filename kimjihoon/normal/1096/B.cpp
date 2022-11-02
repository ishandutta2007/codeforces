#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int	n; cin >> n;
	string s; cin >> s;
	long long cl = 1, cr = 1, ans = 0;
	for (int i = 1; i < n; i++) {
		if (s[i] != s[i - 1]) break;
		cl++;
	}
	for (int i = n - 2; i >= 0; i--) {
		if (s[i] != s[i + 1]) break;
		cr++;
	}
	ans += cl + cr + 1;
	if (s[0] == s[n - 1])
		ans += cl * cr;
	cout << ans % 998244353LL << '\n';
	return 0;
}