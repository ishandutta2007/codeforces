#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int maxn = 524288;

struct segtree_lazy {

	int a[2*maxn];
	int b[2*maxn];

	void init() {
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
	}

	void push(int i) {
		if (b[i]) {
			a[i] += b[i];
			if (i < maxn) {
				b[2*i] += b[i];
				b[2*i+1] += b[i];
			}
			b[i] = 0;
		}
	}

	int get(int l, int r, int node=1, int nl=1, int nr=maxn) {
		push(node);

		if (r < nl || nr < l) {
			return -1;
		}
		if (l <= nl && nr <= r) {
			return a[node];
		}

		int nm = (nl + nr) >> 1;
		return max(get(l, r, 2*node, nl, nm), get(l, r, 2*node+1, nm+1, nr));
	}

	void update(int l, int r, int val, int node=1, int nl=1, int nr=maxn) {

		if (r < nl || nr < l) {
			push(node);
			return;
		}

		if (l <= nl && nr <= r) {
			b[node] += val;
			push(node);
			return;
		}

		push(node);

		int nm = (nl + nr) >> 1;
		update(l, r, val, 2*node, nl, nm);
		update(l, r, val, 2*node+1, nm+1, nr);
		a[node] = max(a[2*node], a[2*node+1]);
	}
};

segtree_lazy drvo;

template<class T, class U>
void cartesian_tree(const T& a, int n, U& l, U& r, U& p) {
	// a must hold unique values, a[0] does not matter
	for (int i=1; i<=n; i++) {
		p[i] = i-1;
		r[i-1] = i;
		while (p[i] && a[i] < a[p[i]]) {
			int j = p[i];
			int k = p[j];
			int v = l[i];
			// rotate
			p[i] = k; r[k] = i;
			p[j] = i; l[i] = j;
			p[v] = j; r[j] = v;
		}
	}
}

int n;
pair<int, int> aa[400005];
int a[200005], p[200005], l[200005], r[200005], dub[200005];

void dfs1(int x) {
	if (l[x])
		dub[l[x]] = dub[x] + 1, dfs1(l[x]);
	if (r[x])
		dub[r[x]] = dub[x] + 1, dfs1(r[x]);
}

int sol[200005];

int fl[400005], fr[400005];

void seek1() {
	basic_string<int> st;
	for (int i=1; i<=2*n; i++) {
		while (st.size() && aa[i] < aa[st.back()]) {
			fr[st.back()] = i;
			st.pop_back();
		}
		st += i;
	}
}

void seek2() {
	basic_string<int> st;
	for (int i=2*n; i>=1; i--) {
		while (st.size() && aa[i] < aa[st.back()]) {
			fl[st.back()] = i;
			st.pop_back();
		}
		st += i;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		aa[i] = {a[i], 0};
		aa[i+n] = {a[i], 1};
	}

	cartesian_tree(a, n, l, r, p);
	dfs1(r[0]);
	seek1();
	seek2();

	for (int i=1; i<=n; i++) {
		// cerr << "dub " << i << ' ' << dub[i] << '\n';
		drvo.update(i, i, dub[i]);
	}

	for (int i=1; i<=n; i++) {
		sol[i-1] = drvo.get(i, i+n-1);
		// cerr << "sol " << i-1 << ' ' << sol[i-1] << '\n';
		// rotiraj
		if (a[i] == 1)
			continue;

		int j = fr[i];
		drvo.update(i+1, j-1, -1);

		int k = fl[i+n];

		// cerr << "stats " << i << ' ' << j << ' ' << k << '\n';

		drvo.update(k+1, i+n-1, 1);
		drvo.update(i+n, i+n, drvo.get(k, k) + 1);
	}

	auto it = min_element(sol, sol+n);
	cout << *it+1 << ' ' << it-sol << '\n';
}