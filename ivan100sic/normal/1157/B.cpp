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

	int n;
	string s;
	map<char, char> mp;

	cin >> n >> s;
	for (char x='1'; x<='9'; x++) {
		char y;
		cin >> y;
		mp[x] = y;
	}

	int st = 0, l = 0, r = -1;
	for (int i=0; i<n; i++) {
		if (st == 0) {
			if (mp[s[i]] > s[i]) {
				st = 1;
				l = i;
			}
		} else if (st == 1) {
			if (mp[s[i]] < s[i]) {
				r = i;
				st = 2;
				break;
			}
		}
	}
	if (st == 1) {
		r = n;
	}

	for (int i=l; i<r; i++) {
		s[i] = mp[s[i]];
	}
	cout << s << '\n';

}