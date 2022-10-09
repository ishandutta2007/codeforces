#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
basic_string<int> e[100005];
ll a[100005];

const int mod = 1'000'000'007;

struct stvar {
	ll g;
	int l, r;
};

ll sol = 0;

void dfs(int x, int p, int d, vector<stvar> b) {
	// dodaj
	for (auto& q : b)
		q.g = gcd(q.g, a[x]);
	b.push_back({a[x], d, d});

	int j = 0;
	for (int i=1; i<(int)b.size(); i++) {
		if (b[i].g == b[j].g) {
			b[j].r = b[i].r;
		} else {
			b[++j] = b[i];
		}
	}
	b.resize(j+1);

	for (auto q : b)
		sol += q.g * (q.r - q.l + 1ll) % mod;

	for (int y : e[x]) {
		if (y == p)
			continue;
		dfs(y, x, d+1, b);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	for (int i=1; i<n; i++) {
		int x, y;
		cin >> x >> y;
		e[x] += y;
		e[y] += x;
	}

	dfs(1, 1, 0, {});

	cout << sol % mod << '\n';
}