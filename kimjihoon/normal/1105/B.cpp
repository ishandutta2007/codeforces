#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	string s; cin >> s;
	int ans = 0;
	for (int i = 'a'; i <= 'z'; i++) {
		int p = 0, c = 0;
		for (int j = 0; j < n; j++) {
			if (s[j] == i)
				c++;
			else
				c = 0;
			if (c == k) {
				p++; c = 0;
			}
		}
		ans = max(ans, p);
	}
	cout << ans << '\n';
	return 0;
}