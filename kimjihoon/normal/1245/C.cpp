#include <iostream>
#include <string>
using namespace std;

long long md = 1000000007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string s; cin >> s;
	long long a = 1, b = 1, ans = 1;
	if (s[0] == 'm' || s[0] == 'w') ans = 0;
	for (int i = 1; i < s.length(); i++) {
		if (s[i] == 'm' || s[i] == 'w') ans = 0;
		if ((s[i] == 'u' && s[i - 1] == 'u') || (s[i] == 'n' && s[i - 1] == 'n')) {
			long long t = a; a = b; b += t;
			b = b % md;
		}
		else {
			ans = (ans * b) % md;
			a = 1; b = 1;
		}
	}
	ans = (ans * b) % md;
	cout << ans << '\n';
	return 0;
}