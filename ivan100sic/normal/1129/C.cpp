#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int M = 1'000'000'007;

int n;
int a[3005];

static inline void ad(int& x, int y) {
	x += y;
	if (x >= M)
		x -= M;
}

struct node {
	int len, link;
	map<int, int> next;
} b[6666];
int sz = 1, last = 0;
int dp[6666];

// shamelessly stolen from cp-algorithms.com
void extend(int c) {
	int cur = sz++;
	b[cur].len = b[last].len + 1;
	int p = last;
	while (p != -1 && !b[p].next.count(c)) {
		b[p].next[c] = cur;
		p = b[p].link;
	}
	if (p == -1) {
		b[cur].link = 0;
	} else {
		int q = b[p].next[c];
		if (b[p].len + 1 == b[q].len) {
			b[cur].link = q;
		} else {
			int clone = sz++;
			b[clone] = b[q];
			b[clone].len = b[p].len + 1;
			while (p != -1 && b[p].next[c] == q) {
				b[p].next[c] = clone;
				p = b[p].link;
			}
			b[q].link = b[cur].link = clone;
		}
	}
	last = cur;
}

basic_string<int> topo() {
	basic_string<int> indeg(sz, 0), sol;
	for (int i=0; i<sz; i++)
		for (auto [p, q] : b[i].next)
			indeg[q]++;
	size_t l = 0;
	for (int i=0; i<sz; i++) {
		if (indeg[i] == 0) {
			sol += i;
		}
	}
	while (l != sol.size()) {
		int x = sol[l++];
		for (auto [p, q] : b[x].next) {
			if (!--indeg[q]) {
				sol += q;
			}
		}
	}
	return sol;
}

void rek_prelazi(int l, int p, int v) {
	if (v == 44 || v == 50 || v == 79 || v == 80)
		return;

	if (v)
		ad(dp[p], dp[l]);

	if (v <= 26) {
		for (auto [x, y] : b[p].next)
			rek_prelazi(l, y, 3*v+1+x);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];

	b[0].link = -1;

	for (int i=1; i<=n; i++) {
		extend(a[i-1]);

		memset(dp, 0, sizeof(dp));
		dp[0] = 1;

		auto w = topo();

		for (int l : w) {
			rek_prelazi(l, l, 0);
		}

		int vr = 0;
		for (int p = 1; p < sz; p++)
			ad(vr, dp[p]);
		cout << vr << '\n';
	}
}