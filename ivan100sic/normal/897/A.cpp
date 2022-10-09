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

	int n, m; string s;
	cin >> n >> m >> s;
	while (m--) {
		int l, r;
		char c, d;
		cin >> l >> r >> c >> d;
		for (int i=l-1; i<r; i++)
			if (s[i] == c)
				s[i] = d;
	}
	cout << s << '\n';
}