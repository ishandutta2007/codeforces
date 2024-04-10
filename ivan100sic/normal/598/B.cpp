// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	string s;
	cin >> s;

	int q;
	cin >> q;

	while (q--) {
		int l, r, k;
		cin >> l >> r >> k;
		l--;
		k %= r-l;

		rotate(begin(s)+l, begin(s)+r-k, begin(s)+r);
	}

	cout << s << '\n';
}