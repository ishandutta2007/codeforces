// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

const ll inf = 1'000000'000000'000005ll;

ll sadd(ll x, ll y) {
	x += y;
	return min(x, inf);
}

// ll smul(ll x, ll y) {
// 	double z = x;
// 	z *= y;
// 	if (z > inf) return inf;
// 	return x * y;
// }

int n, m;
ll k;
string s;
int lcp[1005][1005];
vector<pair<int, int>> subs;

bool cmp(int l, int r, int u, int v) {
	int w = min({r-l, v-u, lcp[l][u]});
	if (w < r-l && w < v-u) {
		return s[l+w] < s[u+w];
	} else {
		return r-l < v-u;
	}
}

ll d[1005][1005];
int veci[1005];

ll dp(int l, int r) {
	for (int i=0; i<n; i++) {
		veci[i] = -1;
		for (int j=i+1; j<=n; j++) {
			if (cmp(l, r, i, j)) {
				veci[i] = j;
				break;
			}
		}
		// cerr << i << " -> " << veci[i] << '\n';
	}

	memset(d, 0, sizeof d);
	d[0][0] = 1;

	for (int j=0; j<m; j++) {
		for (int i=j; i<n; i++) {
			int v = veci[i];
			if (v == -1) continue;
			d[j+1][v] = sadd(d[j+1][v], d[j][i]);
		}

		// prefix sum
		for (int i=0; i<n; i++) {
			d[j+1][i+1] = sadd(d[j+1][i+1], d[j+1][i]);
		}

		// for (int i=0; i<=n; i++) {
		// 	cerr << d[j+1][i] << " \n"[i == n];
		// }
	}

	return d[m][n];
}

string resi(ll k) {
	int l = 0, r = subs.size()-1, o = -1;
	while (l <= r) {
		int mid = (l+r) / 2;
		auto [u, v] = subs[mid];

		ll z = dp(u, v);
		// cerr << "dp " << u << ' ' << v << " -> " << z << '\n';

		if (z < k) {
			o = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}

	{
		auto [l, r] = subs[o];
		return s.substr(l, r-l);
	}
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> m >> k >> s;
	for (int i=n-1; i>=0; i--) {
		for (int j=n-1; j>=0; j--) {
			if (s[i] == s[j]) {
				lcp[i][j] = lcp[i+1][j+1] + 1;
			} else {
				lcp[i][j] = 0;
			}
		}
	}

	for (int l=0; l<n; l++) {
		for (int r=l+1; r<=n; r++) {
			subs.emplace_back(l, r);
		}
	}

	sort(begin(subs), end(subs), [&](auto p, auto q) {
		return cmp(p.first, p.second, q.first, q.second);
	});

	cout << resi(k) << '\n';
}