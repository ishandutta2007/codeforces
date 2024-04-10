#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

vector<int> zfunc(string s) {
	int n = (int)s.size();
	vector<int> z(n, 0);
	for (int i=1, l=0, r=0; i<n; i++) {
		if (i < r) {
			z[i] = min(r-i, z[i-l]);
		} else {
			z[i] = 0;
		}
		while (i + z[i] < n && s[i + z[i]] == s[z[i]])
			z[i]++;
		if (i + z[i] > r) {
			l = i;
			r = i + z[i];
		}
	}
	return z;
}

struct state {
    int len, link, jbg, fpos;
    map<char, int> next;
    basic_string<int> inv_link;
};

const int MAXLEN = 100005;
state st[MAXLEN * 2];
int sz, last;

void sa_init() {
	st[0].len = 0;
	st[0].link = -1;
	sz++;
	last = 0;
}

void sa_extend(char c) {
	int cur = sz++;
	st[cur].fpos = st[cur].len = st[last].len + 1;
	int p = last;
	while (p != -1 && !st[p].next.count(c)) {
		st[p].next[c] = cur;
		p = st[p].link;
	}
	if (p == -1) {
		st[cur].link = 0;
	} else {
		int q = st[p].next[c];
		if (st[p].len + 1 == st[q].len) {
			st[cur].link = q;
		} else {
			int clone = sz++;
			st[clone] = st[q];
			st[clone].len = st[p].len + 1;
			while (p != -1 && st[p].next[c] == q) {
				st[p].next[c] = clone;
				p = st[p].link;
			}
			st[q].link = st[cur].link = clone;
		}
	}
	last = cur;
}

int lol[100005];

void dfs(int x) {

	// cerr << x << ' ' << st[x].fpos << ' ' << st[x].jbg << '\n';

	lol[st[x].fpos] = max(lol[st[x].fpos], st[x].jbg);
	for (int y : st[x].inv_link) {
		st[y].jbg = max(st[y].jbg, st[x].jbg);
		dfs(y);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string p, s;
	cin >> p >> s;
	p = p.substr(1);
	auto z = zfunc(s);
	z.push_back(0);

	sa_init();
	for (char x : p)
		sa_extend(x);

	ll sol = (ll)(p.size() + 1) * (ll)s.size();

	// markiraj
	int w = 0, n = s.size();
	for (int i=0; i<n; i++) {
		char c = s[i];
		if (!st[w].next.count(c))
			break;
		// cerr << "a " << i << ' ' << w << '\n';
		w = st[w].next[c];
		st[w].jbg = z[i+1];
	}

	for (int i=1; i<sz; i++)
		st[st[i].link].inv_link += i;

	dfs(0);

	sol -= accumulate(lol, lol+100005, 0ll);

	cout << sol << '\n';
}