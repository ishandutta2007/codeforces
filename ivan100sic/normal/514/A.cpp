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

	string s;
	cin >> s;
	for (int i=0; i<(int)s.size(); i++) {
		char f = '0' + 9 - (s[i] - '0');
		if (i > 0) {
			s[i] = min(f, s[i]);
		} else if (s[i] != '9') {
			s[i] = min(s[i], f);
		}
	}
	cout << s << '\n';
}