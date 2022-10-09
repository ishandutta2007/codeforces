#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[300005];

struct permutation_tree {

	struct segtree {
		struct node {
			int v, i, lz;
		};

		vector<node> b;
		int maxn;

		void push(int x) {
			if (x < maxn) {
				b[2*x].lz += b[x].lz;
				b[2*x+1].lz += b[x].lz;
			}
			b[x].v += b[x].lz;
			b[x].lz = 0;
		}

		void pull(int x) {
			if (b[2*x].v < b[2*x+1].v) {
				b[x] = b[2*x];
			} else {
				b[x] = b[2*x+1];
			}
		}

		segtree(int n) {
			maxn = 1;
			while (maxn < n)
				maxn <<= 1;
			b.resize(2*maxn);
			for (int i=0; i<maxn; i++)
				b[i + maxn] = {0, i, 0};
			for (int i=maxn-1; i; i--)
				pull(i);
		}

		void update(int l, int r, int v, int x, int xl, int xr) {
			if (r < xl || xr < l) {
				push(x);
				return;
			}
			if (l <= xl && xr <= r) {
				b[x].lz += v;
				push(x);
				return;
			}
			push(x);
			int xm = (xl+xr) >> 1;
			update(l, r, v, 2*x, xl, xm);
			update(l, r, v, 2*x+1, xm+1, xr);
			pull(x);
		}

		void update(int l, int r, int v) {
			update(l, r, v, 1, 0, maxn-1);
		}

		pair<int, int> query(int l, int r, int x, int xl, int xr) {
			push(x);
			if (r < xl || xr < l)
				return {1123123123, -1};
			if (l <= xl && xr <= r)
				return {b[x].v, b[x].i};
			int xm = (xl+xr) >> 1;
			auto pl = query(l, r, 2*x, xl, xm);
			auto pr = query(l, r, 2*x+1, xm+1, xr);
			return pl.first < pr.first ? pl : pr;
		}

		pair<int, int> query(int l, int r) {
			return query(l, r, 1, 0, maxn-1);
		}
	};

	struct node {
		list<node*> ch;
		int l, r, t;
	};

	struct stack_entry {
		int l, r, x;
	};

	node* root;

	permutation_tree(vector<int> a) {
		int n = a.size();
		vector<stack_entry> stmin, stmax;
		segtree b(n); // max - min - len ~ range - len , >= -1, min
		vector<node*> st;
		for (int i=0; i<n; i++) {
			// update stacks, segtree
			int nl = i;
			while (stmin.size() && a[i] < stmin.back().x) {
				auto [l, r, x] = stmin.back();
				stmin.pop_back();
				nl = l;
				b.update(l, r, x);
			}
			stmin.push_back({nl, i, a[i]});
			b.update(nl, i, -a[i]);

			nl = i;
			while (stmax.size() && a[i] > stmax.back().x) {
				auto [l, r, x] = stmax.back();
				stmax.pop_back();
				nl = l;
				b.update(l, r, -x);
			}
			stmax.push_back({nl, i, a[i]});
			b.update(nl, i, a[i]);
			b.update(0, i, -1);
			// probe everything
			// for (int j=0; j<=i; j++)
			// 	cerr << b.query(j, j).first << " \n"[j == i];
			// cerr << "stacks:\n";
			// for (auto [l, r, x] : stmin)
			// 	cerr << l << ' ' << r << ' ' << x << ", ";
			// cerr << '\n';
			// for (auto [l, r, x] : stmax)
			// 	cerr << l << ' ' << r << ' ' << x << ", ";
			// cerr << '\n';

			// merge nodes
			node* curr = new node {{}, a[i], a[i], 0};
			while (st.size()) {
				auto prev = st.back();
				if (prev->r + 1 == curr->l) {
					if (prev->t == 1) {
						prev->ch.push_back(curr);
						prev->r = curr->r;
						curr = prev;
						st.pop_back();
					} else if (curr->t == 1) {
						curr->ch.push_front(prev);
						curr->l = prev->l;
						st.pop_back();
					} else {
						curr = new node {{prev, curr}, prev->l, curr->r, 1};
						st.pop_back();
					}
				} else if (prev->l == curr->r + 1) {
					if (prev->t == 2) {
						prev->ch.push_back(curr);
						prev->l = curr->l;
						curr = prev;
						st.pop_back();
					} else if (curr->t == 2) {
						curr->ch.push_front(prev);
						curr->r = prev->r;
						st.pop_back();
					} else {
						curr = new node {{prev, curr}, curr->l, prev->r, 2};
						st.pop_back();
					}
				} else {
					auto [val, idx] = b.query(0, i-(curr->r - curr->l + 1));
					if (val == -1) {
						list<node*> nuch = {curr};
						int nul = curr->l, nur = curr->r;
						int rem = i - idx + 1 - (curr->r - curr->l + 1);
						while (rem > 0) {
							auto tmp = st.back();
							nul = min(nul, tmp->l);
							nur = max(nur, tmp->r);
							rem -= tmp->r - tmp->l + 1;
							nuch.push_front(tmp);
							st.pop_back();
						}
						curr = new node {nuch, nul, nur, 0};
					} else {
						break;
					}
				}
			}
			st.push_back(curr);
		}
		root = st[0];
	}

	ll dfs(node* curr) {
		ll z = 0;
		if (curr->t) {
			z += curr->ch.size() * (curr->ch.size() - 1ll) / 2;
		} else {
			z++;
		}

		for (auto nx : curr->ch)
			z += dfs(nx);
		return z;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		int x, y;
		cin >> x >> y;
		a[x-1] = y-1;
	}

	// for (int i=0; i<n; i++)
	// 	cerr << a[i] << " \n"[i == n-1];

	permutation_tree tree(vector<int>(a, a+n));

	cout << tree.dfs(tree.root) << '\n';
}