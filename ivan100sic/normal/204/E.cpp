#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct node {
	map<int, int> next;
	int len, link;
	bool is_clone;
};

node b[400005]; int bsz, sa_last;

void sa_init() {
	b[0].link = -1;
	bsz = 1;
	sa_last = 0;
}

void sa_extend(int c) {
	int p = sa_last, curr = bsz++;
	b[curr].len = b[sa_last].len + 1;
	for (; p != -1 && !b[p].next.count(c); p = b[p].link)
		b[p].next[c] = curr;
	if (p == -1) {
		b[curr].link = 0;
	} else {
		int q = b[p].next[c];
		if (b[p].len + 1 == b[q].len) {
			b[curr].link = q;
		} else {
			int clone = bsz++;
			b[clone].len = b[p].len + 1;
			b[clone].next = b[q].next;
			b[clone].link = b[q].link;
			b[clone].is_clone = true;
			for (; p != -1 && b[p].next[c] == q; p = b[p].link)
				b[p].next[c] = clone;
			b[curr].link = b[q].link = clone;
		}
	}
	sa_last = curr;
}

basic_string<int> e[400005];
int el[400005], er[400005], et;
int flat[400005];

int n, k, m;
string a[100005];
int id[200005], st[100005];
int cnt[400005], reach[400005], uqc;
bool good[400005];
int upgood[400005];

void dfs1(int x) {
	flat[et] = id[b[x].is_clone ? 0 : b[x].len];
	el[x] = et++;
	for (int y : e[x]) {
		dfs1(y);
	}
	er[x] = et;
}

void dfs2(int x) {
	if (good[x])
		upgood[x] = x;
	else
		upgood[x] = upgood[b[x].link];
	for (int y : e[x])
		dfs2(y);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	sa_init();
	id[0] = 400004;

	for (int i=0; i<n; i++) {
		cin >> a[i];
		st[i] = m;
		for (char c : a[i]) {
			sa_extend(c);
			id[++m] = i;
		}
		sa_extend(i + 123123123);
		id[++m] = i;
	}

	for (int i=1; i<bsz; i++)
		e[b[i].link] += i;

	dfs1(0);

	cnt[400004] = 1;

	for (int l=0, r=0; l<bsz; l++) {
		while (r < bsz && uqc < k) {
			uqc += ++cnt[flat[r++]] == 1;
		}
		reach[l] = r + (uqc != k);
		uqc -= --cnt[flat[l]] == 0;
	}

	for (int i=0; i<bsz; i++) {
		good[i] = reach[el[i]] <= er[i];
	}

	dfs2(0);

	if (k == 1) {
		for (int i=0; i<n; i++) {
			cout << a[i].size() * (a[i].size()+1ll) / 2 << " \n"[i == n-1];
		}
	} else {
		for (int i=0; i<n; i++) {
			int p = 0;
			ll sol = 0;
			for (char c : a[i]) {
				p = b[p].next[c];
				sol += b[upgood[p]].len;
			}
			cout << sol << " \n"[i == n-1];
		}
	}
}