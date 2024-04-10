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
	string s, p;
	cin >> n >> s;
	char x = 0;
	for (int i=0; i<n; i++) {
		if (x == 0) {
			x = s[i];
		} else if (s[i] != x) {
			p += x;
			p += s[i];
			x = 0;
		}
	}
	cout << s.size() - p.size() << '\n' << p << '\n';
}