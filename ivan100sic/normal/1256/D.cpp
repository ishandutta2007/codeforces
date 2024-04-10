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

	int q;
	cin >> q;
	while (q--) {
		int n;
		ll k;
		string s;
		cin >> n >> k >> s;
		vector<int> z;
		for (int i=0; i<n; i++) {
			if (s[i] == '0') {
				z.push_back(i);
			}
		}
		int c = 0;
		for (int& x : z) {
			int d = min<ll>(k, x-c);
			x -= d;
			k -= d;
			c++;
		}
		string t(n, '1');
		for (int x : z)
			t[x] = '0';
		cout << t << '\n';
	}
}