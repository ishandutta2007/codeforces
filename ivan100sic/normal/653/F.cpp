#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MAX_SUFFIX_AUTOMATON_SIZE = 1000005;

struct node {
	int link, len, firstpos;
	map<char, int> next;
} b[MAX_SUFFIX_AUTOMATON_SIZE]; int sz, last;

void extend(char c) {
	int curr = sz++;
	b[curr].firstpos = b[curr].len = b[last].len + 1;
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
			b[clone].next = b[q].next;
			b[clone].link = b[q].link;
			b[clone].len = b[p].len + 1;
			b[clone].firstpos = b[q].firstpos;
			while (p != -1 && b[p].next[c] == q) {
				b[p].next[c] = clone;
				p = b[p].link;
			}
			b[curr].link = b[q].link = clone;
		}
	}
	last = curr;
}

basic_string<int> topo() {
	basic_string<int> a(sz, 0);
	iota(a.begin(), a.end(), 0);
	sort(a.begin(), a.end(), [&](int i, int j) {
		return b[i].len < b[j].len;
	});
	return a;
}

int n;
string s;
int lo[1000005], hi[1000005];
int z[500005];
basic_string<int>* e;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> s;
	sz = 1;
	b[0].link = -1;
	for (char x : s)
		extend(x);
	for (int i=0; i<n; i++)
		z[i+1] = z[i] + (s[i] == '(' ? 1 : -1);

	e = new basic_string<int>[1000005] + 500002;

	for (int i=0; i<=n; i++)
		e[z[i]] += i;

	auto w = topo();
	ll sol = 0;

	memset(lo, 63, sizeof(lo));
	lo[0] = hi[0] = 0;
	for (int x : w) {
		for (auto [c, y] : b[x].next) {
			lo[y] = min(lo[y], lo[x] + 1);
			hi[y] = max(hi[y], hi[x] + 1);
		}
	}

	for (int x : w) {
		if (!x) continue;
		int r = b[x].firstpos;
		int m = r - lo[x];
		int l = r - hi[x];

		// cerr << "trying suffix group " << l << ' ' << m << ' ' << r << '\n';

		auto it = lower_bound(e[z[r] - 1].begin(), e[z[r] - 1].end(), r);

		int j;
		if (it == e[z[r] - 1].begin()) {
			j = l;
		} else {
			j = max(l, *prev(it) + 1);
		}

		if (j > m)
			continue;

		auto it1 = lower_bound(e[z[r]].begin(), e[z[r]].end(), j);
		auto it2 = lower_bound(e[z[r]].begin(), e[z[r]].end(), m+1);

		// cerr << "suffix " << l << ' ' << m << ' ' << r << " contributes " << it2-it1 << '\n';
		// cerr << "j was " << j << '\n';

		sol += it2 - it1;
	}

	cout << sol << '\n';
}