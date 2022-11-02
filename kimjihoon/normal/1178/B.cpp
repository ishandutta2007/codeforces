#include <iostream>
#include <string>
using namespace std;

int l[1000009], r[1000009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string s; cin >> s;
	int c = 0;
	for (int i = 1; i < s.length(); i++) {
		if (s[i] == 'v' && s[i - 1] == 'v') c++;
		l[i] = c;
	}
	c = 0;
	for (int i = (int)s.length() - 2; i >= 0; i--) {
		if (s[i] == 'v' && s[i + 1] == 'v') c++;
		r[i] = c;
	}
	long long ans = 0;
	for (int i = 0; i < s.length(); i++)
		if (s[i] == 'o')
			ans += 1LL * l[i] * r[i];
	cout << ans << '\n';
	return 0;
}