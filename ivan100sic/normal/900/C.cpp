#include <bits/stdc++.h>
using namespace std;

int n;
int a[100005];
bool kand[100005];
int pref[100005];

int inv[100005];

template<int MAXN>
struct segtree {
	
	struct node_t {
		/* DATA MEMBERS */
		int x;

		/* CONSTRUCTOR */
		node_t(int x = 123123123) : x(x) {}

		node_t& operator+= (const node_t& other) {
			/* ADDITION */
			if (other.x < x) {
				x = other.x;
			}

			return *this;
		}

		node_t operator+ (const node_t& other) const {
			node_t tmp = *this;
			tmp += other;
			return tmp;
		}
	};

	node_t a[2*MAXN];

	void init() {
		for (int i=1; i<=n; i++) {
			/* KOPIRAJ NEKI EKSTERNI NIZ OVDE */
			a[i + MAXN - 1] = inv[i];
		}
		for (int i=MAXN-1; i>0; i--) {
			a[i] = a[2*i] + a[2*i+1];
		}
	}

	node_t get(int l, int r, int node=1, int nl=1, int nr=MAXN) {
		if (r < nl || nr < l) {
			return node_t();
		}
		if (l <= nl && nr <= r) {
			return a[node];
		}

		int nm = (nl + nr) >> 1;
		return get(l, r, 2*node, nl, nm) + get(l, r, 2*node+1, nm+1, nr);
	}

	void add(int pos, node_t val) {
		pos += MAXN-1;
		a[pos] += val;
		while (pos > 1) {
			pos >>= 1;
			a[pos] = a[2*pos] + a[2*pos+1];
		}
	}

	void set(int pos, node_t val) {
		pos += MAXN-1;
		a[pos] = val;
		while (pos > 1) {
			pos >>= 1;
			a[pos] = a[2*pos] + a[2*pos+1];
		}
	}
};

segtree<131072> drvo;

int pref_max[100005];
int sled[100005];
int sled_run[100005];
int run_len[100005];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		inv[a[i]] = i;
	}

	for (int i=1; i<=n; i++) {
		pref_max[i] = max(pref_max[i-1], a[i]);
	}

	vector<int> stek;

	for (int i=1; i<=n; i++) {
		while (stek.size() && stek.back() < a[i]) {
			sled[inv[stek.back()]] = i;
			stek.pop_back();
		}
		stek.push_back(a[i]);
	}

	for (int i=n; i>=1; i--) {
		if (sled[i] == 0) {
			sled_run[i] = 1;
		} else {
			sled_run[i] = sled_run[sled[i]] + 1;
		}
	}

	for (int i=1; i<=n; i++) {
		if (pref_max[i] == a[i]) {
			run_len[i] = run_len[inv[pref_max[i-1]]] + 1;
		}
	}

	int best_run = -1, sol = -1;

	for (int i=n; i>=1; i--) {
		// sta ako sklonim njega
		int pre = pref_max[i-1];
		int desno_veci = drvo.get(pre+1, n).x;

		int run = run_len[inv[pre]];

		if (desno_veci != 123123123) {
			run += sled_run[desno_veci];
		}

		// cerr << i << ' ' << a[i] << ' ' << run << '\n';

		if (run > best_run) {
			best_run = run;
			sol = a[i];
		} else if (run == best_run) {
			sol = min(sol, a[i]);
		}

		drvo.set(a[i], i);
	}

	cout << sol;


}