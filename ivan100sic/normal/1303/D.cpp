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
		vector<int> f(64);
		ll k;
		int n;
		cin >> k >> n;
		while (n--) {
			int x;
			cin >> x;
			f[31 - __builtin_clz(x)]++;
		}
		int ok = 1;
		ll moves = 0;
		for (int i=0; i<62; i++) {
			if (k & (1ll << i)) {
				int j = i;
				while (j < 63 && f[j] == 0)
					j++;
				if (j == 63) {
					ok = 0;
					break;
				}
				if (j != i) {
					for (int k=i+1; k<j; k++)
						f[k]++;
					f[j]--;
					f[i] += 2;
					f[i] -= 1;
					moves += j-i;
				} else {
					f[i]--;
				}
			}
			f[i+1] += f[i] / 2;
		}

		if (!ok)
			moves = -1;
		cout << moves << '\n';
	}
}