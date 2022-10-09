#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct node {
	int link, len, cnt;
	map<char, int> next;
} b[400005]; int sz, last;

int n;
string s, ok;

void extend(char c, int k) {
	int curr = sz++;
	b[curr].len = b[last].len + 1;
	b[curr].cnt = k;
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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> s >> ok;
	sz = 1;
	b[0].link = -1;

	for (int i=0; i<n; i++) {
		extend(s[i], ok[i] == '0');
	}

	auto w = topo();
	auto wr = w;
	reverse(wr.begin(), wr.end());
	ll sol = 0;
	for (int x : wr) {
		if (x) {
			b[b[x].link].cnt += b[x].cnt;
			sol = max(sol, b[x].cnt * 1ll * b[x].len);
		}
	}
	cout << sol << '\n';
}