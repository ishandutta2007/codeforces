#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		string s, t, p;
		cin >> s >> t >> p;
		map<char, int> mp;
		for (char x : p)
			mp[x]++;
		size_t i = 0;
		bool ok = true;
		for (char x : t) {
			if (i < s.size() && s[i] == x)
				i++;
			else if (mp[x] > 0)
				mp[x]--;
			else {
				ok = false;
				break;
			}
		}
		if (ok && i == s.size())
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}