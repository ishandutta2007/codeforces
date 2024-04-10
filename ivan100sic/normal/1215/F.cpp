#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, p, M, m;

int yesnode(int x) { return 0*444444+x; }
int nonode (int x) { return 1*444444+x; }
int geqval (int x) { return 2*444444+x; }
int lesval (int x) { return 3*444444+x; }

const int truenode = 1777770;
const int falsenode = 1777771;

int kontra(int x) {
	if (x == truenode)
		return falsenode;
	if (x == falsenode)
		return truenode;

	if (x < 1*444444) {
		return x + 444444;
	} else if (x < 2*444444) {
		return x - 444444;
	} else if (x < 3*444444) {
		return x + 444444;
	} else {
		return x - 444444;
	}
}

const int hi = 1777777;

basic_string<int> e[hi], st;

int idx[hi], low[hi], cc[hi], t, br, val[hi];
bool inst[hi];

void add_edge(int x, int y) {
	e[x] += y;
	e[kontra(y)] += kontra(x);
}

void scc(int x) {
	idx[x] = low[x] = ++t;
	inst[x] = true;
	st += x;
	for (int y : e[x]) {
		if (idx[y] == 0) {
			scc(y);
			low[x] = min(low[y], low[x]);
		} else if (inst[y]) {
			low[x] = min(low[x], idx[y]);
		}
	}
	if (low[x] == idx[x]) {
		++br;
		while (1) {
			int z = st.back();
			st.pop_back();
			cc[z] = br;
			inst[z] = false;
			if (z == x)
				break;
		}
	}
}

void no() {
	cout << "-1\n";
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> p >> M >> m;
	for (int i=0; i<n; i++) {
		int x, y;
		cin >> x >> y;
		add_edge(nonode(x), yesnode(y));
		add_edge(nonode(y), yesnode(x));
	}

	for (int i=1; i<=p; i++) {
		int l, r;
		cin >> l >> r;
		add_edge(yesnode(i), geqval(l));
		add_edge(yesnode(i), lesval(r+1));
	}

	for (int i=0; i<m; i++) {
		int x, y;
		cin >> x >> y;
		add_edge(yesnode(x), nonode(y));
		add_edge(yesnode(y), nonode(x));
	}

	for (int i=1; i<=M; i++) {
		add_edge(geqval(i+1), geqval(i));
	}

	add_edge(falsenode, truenode);
	add_edge(truenode, geqval(1));
	add_edge(truenode, lesval(M+1));

	for (int i=0; i<hi; i++)
		if (!idx[i])
			scc(i);

	for (int i=1; i<=p; i++)
		if (cc[yesnode(i)] == cc[nonode(i)])
			no();

	for (int i=1; i<=M+1; i++)
		if (cc[geqval(i)] == cc[lesval(i)])
			no();

	vector<int> relevant = {truenode, falsenode};
	for (int i=1; i<=M+1; i++) {
		relevant.push_back(geqval(i));
		relevant.push_back(lesval(i));
	}
	for (int i=1; i<=p; i++) {
		relevant.push_back(yesnode(i));
		relevant.push_back(nonode(i));
	}

	sort(relevant.begin(), relevant.end(), [&](int x, int y) {
		return cc[x] < cc[y];
	});

	for (int x : relevant) {
		if (!val[kontra(x)]) {
			val[x] = true;
		}
	}

	{
		int k = 0, f = 0;
		for (int i=1; i<=M; i++)
			if (val[geqval(i)])
				f = i;
		for (int i=1; i<=p; i++)
			if (val[yesnode(i)])
				k++;
		cout << k << ' ' << f << '\n';
		for (int i=1; i<=p; i++)
			if (val[yesnode(i)])
				cout << i << ' ';
		cout << '\n';
	}
}