#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int a[200009];
vector<int> v;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		string s; cin >> s;
		v.clear();
		int c = 0;
		for (int i = 0; i < s.length(); i++) {
			c++;
			if (i + 1 == s.length() || s[i] != s[i + 1]) {
				v.push_back(c);
				c = 0;
			}
		}
		if (v.size() == 1) {
			cout << (n + 2) / 3 << '\n';
			continue;
		}
		if (s[0] == s[(int)s.length() - 1]) {
			v[0] += v.back(); v.pop_back();
		}
		int ans = 0;
		for (int i = 0; i < v.size(); i++)
			ans += v[i] / 3;
		cout << ans << '\n';
	}
	return 0;
}