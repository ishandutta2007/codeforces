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

	int n, x, y;
	string s;
	cin >> n >> x >> y >> s;
	int stanje = -1, broj = 0;
	for (char c : s) {
		if (stanje == -1) {
			if (c == '0')
				stanje = 0, broj = 1;
			else
				stanje = 1, broj = 0;
		} else if (stanje == 0) {
			if (c == '1')
				stanje = 1;
		} else if (stanje == 1) {
			if (c == '0')
				broj++, stanje = 0;
		}
	}

	cout << (broj ? (broj-1ll) * min(x, y) + y : 0) << '\n';
}