// I've decided to retire from ALL contests
// It's been a nice ride... but I need to move on
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
		int n, k;
		string s;
		cin >> n >> k >> s;

		vector<basic_string<int>> e(n);

		auto ae = [&](int x, int y) {
			e[x] += y;
			e[y] += x;
		};

		for (int i=0; i<n; i++)
			ae(i, n-1-i);
		for (int i=k; i<n; i++)
			ae(i, i-k);

		string v(n, 0);

		int sol = 0;

		for (int i=0; i<n; i++) {
			if (v[i])
				continue;
			basic_string<int> q = {i};
			v[i] = 1;
			map<int, int> amt;
			amt[s[i]]++;
			int h = 1;
			size_t qs = 0;
			while (qs != q.size()) {
				int x = q[qs++];
				for (int y : e[x]) {
					if (!v[y]) {
						v[y] = 1;
						q += y;
						h = max(h, ++amt[s[y]]);
					}
				}
			}
			sol += qs - h;
		}

		cout << sol << '\n';
	}
}

// I will still practice daily...