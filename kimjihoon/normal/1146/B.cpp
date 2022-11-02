#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string s; cin >> s;
	string p = "";
	for (int i = 0; i < s.length(); i++)
		if (s[i] != 'a')
			p += s[i];
	if (p.length() % 2) {
		cout << ":(" << '\n';
		return 0;
	}
	for (int i = 0; i < p.length() / 2; i++)
		if (p[i] != p[i + p.length() / 2]) {
			cout << ":(" << '\n';
			return 0;
		}
	int c = 0;
	string ans = "";
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != 'a') c++;
		if (c > p.length() / 2) break;
		ans += s[i];
	}
	string pa = ans;
	for (int i = 0; i < p.length() / 2; i++)
		pa += p[i];
	if (s == pa) cout << ans << '\n';
	else cout << ":(" << '\n';
	return 0;
}