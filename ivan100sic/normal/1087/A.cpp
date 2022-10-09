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

	string s, p;
	cin >> s;
	int l = 0, r = s.size() - 1;
	int z = s.size() % 2;
	while (l <= r) {
		if (z) {
			p += s[l++];
		} else {
			p += s[r--];
		}
		z ^= 1;
	}
	reverse(p.begin(), p.end());
	cout << p << '\n';
}