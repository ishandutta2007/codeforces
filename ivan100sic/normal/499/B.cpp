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

	int n, m;
	map<string, string> mp;
	cin >> n >> m;
	while (m--) {
		string a, b;
		cin >> a >> b;
		mp[a] = b;
	}
	while (n--) {
		string s;
		cin >> s;
		if (mp[s].size() < s.size())
			s = mp[s];
		cout << s << ' ';
	}
	cout << '\n';
}