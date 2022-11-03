#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct vert {
	int p, t, x;
};

vector<int> t;
vector<int> p;

void push(int v) {
	t[2 * v] += p[v];
	t[2 * v + 1] += p[v];
	p[2 * v] += p[v];
	p[2 * v + 1] += p[v];
	p[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int val) {
	if (l > r)
		return;
	if (tl == l && tr == r) {
		t[v] += val;
		p[v] += val;
	}
	else {
		push(v);
		int tm = (tl + tr) / 2;
		update(2 * v, tl, tm, l, min(r, tm), val);
		update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, val);
		t[v] = max(t[2 * v], t[2 * v + 1]);
	}
	return;
}

int get(int v, int tl, int tr) {
	if (tl == tr)
		if (t[v] >= 1)
			return tl;
		else
			return -1;
	int tm = (tl + tr) / 2;
	push(v);
	if (t[2 * v + 1] >= 1)
		return get(2 * v + 1, tm + 1, tr);
	else
		return get(2 * v, tl, tm);
}

int main() {
	ios_base::sync_with_stdio(false);
	int m;
	cin >> m;
	vector<vert> a(m);
	vector<int> b(m);
	for (int i = 0; i < m; i++) {
		cin >> a[i].p >> a[i].t;
		if (a[i].t)
			cin >> a[i].x;
		b[a[i].p - 1] = a[i].x;
	}
	t.resize(4 * m);
	p.resize(4 * m);
	for (int i = 0; i < m; i++) {
		if (a[i].t) {
			update(1, 0, m - 1, 0, a[i].p - 1, 1);
		}
		else {
			update(1, 0, m - 1, 0, a[i].p - 1, -1);
		}
		int pos = get(1, 0, m - 1);
		if (pos != -1)
			cout << b[pos] << '\n';
		else
			cout << pos << '\n';
	}
	return 0;
}