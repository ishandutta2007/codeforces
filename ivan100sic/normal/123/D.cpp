#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct node {
	int link, len;
	map<char, int> next;
	bool is_clone;
} b[200005]; int sz, last;

void extend(char c) {
	int curr = sz++;
	b[curr].len = b[last].len + 1;
	int p = last;
	while (p != -1 && b[p].next.count(c) == 0) {
		b[p].next[c] = curr;
		p = b[p].link;
	}
	if (p == -1) {
		b[curr].link = 0;
	} else {
		int q = b[p].next[c];
		if (b[p].len + 1 == b[q].len) {
			b[curr].link = q;
		} else {
			int clone = sz++;
			b[clone] = b[q];
			b[clone].is_clone = true;
			b[clone].len = b[p].len + 1;
			while (p != -1 && b[p].next[c] == q) {
				b[p].next[c] = clone;
				p = b[p].link;
			}
			b[q].link = b[curr].link = clone;
		}
	}
	last = curr;
}

basic_string<int> topo() { // glup sam
	basic_string<int> indeg(sz, 0), sol;
	size_t qs = 0;
	for (int i=0; i<sz; i++) {
		for (auto [x, y] : b[i].next) {
			indeg[y]++;
		}
	}
	for (int i=0; i<sz; i++)
		if (indeg[i] == 0)
			sol += i;
	while (qs != sol.size()) {
		int x = sol[qs++];
		for (auto [c, y] : b[x].next)
			if (!--indeg[y])
				sol += y;
	}
	return sol;
}

ll x[200005], sol, cnt[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string s;
	cin >> s;

	sz = 1;
	b[0].link = -1;

	for (char x : s)
		extend(x);
	auto w = topo();

	for (int i=1; i<sz; i++)
		if (!b[i].is_clone) cnt[i] = 1;

	for (int i=sz-1; i>0; i--) {
		int x = w[i];
		// cerr << "link " << x << ' ' << b[x].link << '\n';
		cnt[b[x].link] += cnt[x];
	}

	x[0] = 1;
	for (int u : w) {
		if (u) {
			// cerr << "dodajem " << u << ' ' << cnt[u] << ' ' << x[u] << '\n';
			sol += cnt[u] * (cnt[u] + 1ll) * x[u];
		}
		for (auto [g, v] : b[u].next) {
			// cerr << "push " << u << ' ' << v << '\n';
			x[v] += x[u];
		}
	}
	cout << sol/2 << '\n';
}