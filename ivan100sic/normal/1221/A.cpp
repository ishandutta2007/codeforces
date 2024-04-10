#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int v2(int x) {
	int y = 0;
	while (x > 1)
		y++, x >>= 1;
	return y;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int s[15];
		memset(s, 0, sizeof(s));
		for (int i=0; i<n; i++) {
			int x;
			cin >> x;
			if (x > 2048)
				continue;
			x = v2(x);
			s[x]++;
		}

		while (1) {
			bool ok = false;
			for (int i=0; i<11; i++)
				if (s[i] >= 2)
					s[i] -= 2, s[i+1]++, ok = 1;
			if (!ok)
				break;
		}
		if (s[11]) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}