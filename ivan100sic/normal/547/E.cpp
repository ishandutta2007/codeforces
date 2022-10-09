#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct node {
	int len, link, id;
	map<char, int> next;
	vector<int> inv;
	int l, r;
} b[800005]; int sz;

int extend(int last, char c, int id) {
	int curr = sz++;
	b[curr].id = id;
	b[curr].len = b[last].len + 1;
	int p = last;
	for (; p != -1 && !b[p].next.count(c); p = b[p].link)
		b[p].next[c] = curr;
	if (p == -1) {
		b[curr].link = 0;
	} else {
		int q = b[p].next[c];
		if (b[p].len + 1 == b[q].len) {
			b[curr].link = q;
		} else {
			int clone = sz++;
			b[clone].len = b[p].len + 1;
			b[clone].link = b[q].link;
			b[clone].next = b[q].next;
			for (; p != -1 && b[p].next[c] == q; p = b[p].link)
				b[p].next[c] = clone;
			b[q].link = b[curr].link = clone;
		}
	}
	return curr;
}

// fenwick
int ff[200005];

void fadd(int x, int y) {
	if (!x) return;
	for (; x<200005; x+=x&-x)
		ff[x] += y;
}

int fget(int x) {
	int y = 0;
	for (; x; x-=x&-x)
		y += ff[x];
	return y;
}

int n, q;
string s[200005];
int prefix[200005];
int idd[800005];

int dt = 1;
void dfs(int x) {
	idd[dt] = b[x].id;
	b[x].l = dt++;
	for (int y : b[x].inv)
		dfs(y);
	b[x].r = dt;
}

vector<int> e[800005];
int ql[500005], qr[500005], ans[500005];

int walk(const string& s) {
	int x = 0;
	for (char c : s)
		x = b[x].next[c];
	return x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> q;

	// init
	sz = 1;
	b[0].link = -1;
	int last = 0;

	for (int i=1; i<=n; i++) {
		cin >> s[i];
		for (char c : s[i])
			last = extend(last, c, i);
		last = extend(last, '$', 0);
	}

	for (int i=1; i<=n; i++)
		prefix[i] = walk(s[i]);

	for (int i=1; i<sz; i++)
		b[b[i].link].inv.push_back(i);
	dfs(0);

	for (int i=1; i<=q; i++) {
		int k;
		cin >> ql[i] >> qr[i] >> k;
		k = prefix[k];
		e[b[k].l-1].push_back(-i);
		e[b[k].r-1].push_back(i);
	}

	for (int t=0; t<=800001; t++) {
		fadd(idd[t], 1);
		for (int x : e[t]) {
			int sgn = 1;
			if (x < 0)
				x = -x, sgn = -1;
			ans[x] += sgn * (fget(qr[x]) - fget(ql[x]-1));
		}
	}

	for (int i=1; i<=q; i++)
		cout << ans[i] << '\n';
}