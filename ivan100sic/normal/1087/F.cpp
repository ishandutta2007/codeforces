#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int f[3][200005];
set<int> e[3];

void add(int* a, int x, int v) {
	for (int i=x; i<200005; i+=i&-i)
		a[i] += v;
}

int get(int* a, int x) {
	int v = 0;
	for (int i=x; i>0; i-=i&-i)
		v += a[i];
	return v;
}

int ord(char x) {
	if (x == 'R')
		return 0;
	else if (x == 'P')
		return 1;
	else if (x == 'S')
		return 2;
	return -1;
}

string s;
int n, q;

int resi(int x, int y, int z) {
	basic_string<int> q;
	if (e[y].size()) {
		q += *e[y].begin();
		q += *e[y].rbegin();
	}
	if (e[z].size()) {
		q += *e[z].begin();
		q += *e[z].rbegin();
	}
	q += 0;
	q += n+1;
	sort(q.begin(), q.end());
	int sol = 0;
	q.resize(unique(q.begin(), q.end()) - q.begin());
	for (int i=0; i<(int)q.size()-1; i++) {
		int l = q[i];
		int r = q[i+1];
		// gledamo oblast do l i od r do kraja
		int xc = get(f[x], r-1) - get(f[x], l);
		if (!xc)
			continue;
		int ylevo = get(f[y], l);
		int zlevo = get(f[z], l);
		int ydesno = get(f[y], n) - get(f[y], r-1);
		int zdesno = get(f[z], n) - get(f[z], r-1);

		int ok = 1;
		if (ylevo && !zlevo)
			ok = 0;
		if (ydesno && !zdesno)
			ok = 0;
		if (ok)
			sol += xc;
	}
	return sol;
}

void resi() {
	int z = 0;
	z += resi(0, 1, 2);
	z += resi(1, 2, 0);
	z += resi(2, 0, 1);
	cout << z << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> q >> s;
	s = string(" ") + s;
	for (int i=1; i<=n; i++) {
		add(f[ord(s[i])], i, 1);
		e[ord(s[i])].insert(i);
	}
	resi();
	while (q--) {
		int x; char c;
		cin >> x >> c;
		add(f[ord(s[x])], x, -1);
		e[ord(s[x])].erase(x);
		s[x] = c;
		add(f[ord(s[x])], x, +1);
		e[ord(s[x])].insert(x);
		resi();
	}
}