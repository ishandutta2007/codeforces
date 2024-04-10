#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int r[500009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	string s; cin >> s;
	long long ans = 0, sp = 0;
	int c = 0, pr = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '1') {
			c++;
			sp += i - r[c] + 1;
			ans += sp;
		}
		else {
			ans += sp;
			for (int j = pr; j < i; j++) {
				r[c] = j + 1;
				c--;
			}
			pr = i + 1;
		}
	}
	cout << ans << '\n';
	return 0;
}