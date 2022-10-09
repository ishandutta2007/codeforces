#include <bits/stdc++.h>
using namespace std;

// Credits:
// https://sites.google.com/site/indy256/algo/link-cut-tree

// also, myself for cleaning the code substantially

namespace link_cut_tree {

	// tree setup
	struct updater {
		/* DATA MEMBERS */
		int x;

		updater(int x) : x(x) {}
		updater() : x(0) {}

		updater& operator+= (const updater& other) {
			/* ADDITION */
			x ^= other.x;

			return *this;
		}

		operator bool () const {
			/* BOOL CAST */
			return x != 0;
		}
	};
	
	struct value {
		/* DATA MEMBERS */
		int x = 0;
		int len = 0;

		/* CONSTRUCTOR */
		value() {}
		value(int x) : x(x), len(1) {}

		value& operator+= (const value& other) {
			/* ADDITION */
			x ^= other.x;
			len += other.len;
			return *this;
		}

		value& operator+= (const updater& other) {
			/* UPDATE ADDITION */
			if (len & 1) {
				x ^= other.x;
			}

			return *this;
		}

		value operator+ (const value& other) const {
			value tmp = *this;
			tmp += other;
			return tmp;
		}
	};

	struct node {
		value nodeValue;
		value subTreeValue;
		updater delta;
		int size;
		bool revert;
		node* left;
		node* right;
		node* parent;

		node(value val) {
			nodeValue = val;
			subTreeValue = val;
			left = right = parent = nullptr;
			size = 1;
		}

		bool isRoot() {
			return !parent || (parent->left != this && parent->right != this);
		}

		static int getSize(node* root) {
			return root ? root->size : 0;
		}

		static value getSubTreeValue(node* root) {
			return root ? root->subTreeValue : value();
		}

		void push() {
			if (revert) {
				revert = false;
				swap(left, right);
				if (left) {
					left->revert ^= true;
				}
				if (right) {
					right->revert ^= true;
				}
			}

			nodeValue += delta;
			subTreeValue += delta;

			if (left) {
				left->delta += delta;
			}
			if (right) {
				right->delta += delta;
			}
		}

		void update() {
			subTreeValue = getSubTreeValue(left) + nodeValue
				+ getSubTreeValue(right);
			size = 1 + getSize(left) + getSize(right);
		}
	};

	void connect(node* ch, node* p, bool isLeftChild) {
		if (ch) {
			ch->parent = p;
		}
		if (isLeftChild) {
			p->left = ch;
		} else {
			p->right = ch;
		}
	}

	void connect(node* ch, node* p) {
		if (ch) {
			ch->parent = p;
		}
	}

	void rotate(node* x) {
		node* p = x->parent;
		node* g = p->parent;

		bool isRootP = p->isRoot();
		bool leftChildX = x == p->left;

		connect(leftChildX ? x->right : x->left, p, leftChildX);
		connect(p, x, !leftChildX);
		if (!isRootP) {
			connect(x, g, p == g->left);
		} else {
			connect(x, g);
		}
		p->update();
	}

	void splay(node* x) {
		while (!x->isRoot()) {
			node* p = x->parent;
			node* g = p->parent;

			if (!p->isRoot()) {
				g->push();
			}
			p->push();
			x->push();
			if (!p->isRoot()) {
				rotate((x == p->left) == (p == g->left) ? p : x);
			}
			rotate(x);
		}
		x->push();
		x->update();
	}

	node* expose(node* x) {
		node* last = nullptr;
		for (node* y = x; y != nullptr; y = y->parent) {
			splay(y);
			y->left = last;
			last = y;
		}
		splay(x);
		return last;
	}

	void makeRoot(node* x) {
		expose(x);
		x->revert ^= true;
	}

	bool connected(node* x, node* y) {
		if (x == y) {
			return true;
		}

		expose(x);
		expose(y);

		return x->parent != nullptr;
	}

	void link(node* x, node* y) {
		makeRoot(x);
		x->parent = y;
	}

	void cut(node* x, node* y) {
		makeRoot(x);
		expose(y);

		y->right->parent = nullptr;
		y->right = nullptr;
	}

	value query(node* from, node* to) {
		makeRoot(from);
		expose(to);
		return node::getSubTreeValue(to);
	}

	void modify(node* from, node* to, updater upd) {
		makeRoot(from);
		expose(to);
		to->delta += upd;
	}
}

using namespace link_cut_tree;

int n, m;
vector<int> e[300005];
int rm[300005];
node* b[300005];

int active_l, active_r;

bool add_node(int x) {
	vector<pair<node*, node*>> linx;

	for (int y : e[x]) if (active_l <= y && y <= active_r) {
		if (connected(b[x], b[y])) {
			// unrolluj
			while (linx.size()) {
				cut(linx.back().first, linx.back().second);
				linx.pop_back();
			}
			return false;
		} else {
			link(b[x], b[y]);
			linx.push_back({b[x], b[y]});
		}
	}

	return true;
}

void remove_node(int x) {
	for (int y : e[x]) if (active_l <= y && y <= active_r) {
		if (connected(b[x], b[y])) {
			cut(b[x], b[y]);
		}
	}
}

template<int MAXN>
struct segtree_lazy {

	struct updater {
		/* DATA MEMBERS */
		long long x;

		updater(long long x = 0) : x(x) {}

		updater& operator+= (const updater& other) {
			/* ADDITION */
			x += other.x;

			return *this;
		}

		operator bool () const {
			/* BOOL CAST */
			return x != 0;
		}
	};
	
	struct node_t {
		/* DATA MEMBERS */
		long long x, len;

		/* CONSTRUCTOR */
		node_t() : x(0), len(0) {}

		node_t(long long x, long long len) : x(x), len(len) {}

		node_t& operator+= (const node_t& other) {
			/* ADDITION */
			x += other.x;
			len += other.len;

			return *this;
		}

		node_t& operator+= (const updater& other) {
			/* UPDATE ADDITION */
			x += other.x * len;

			return *this;
		}

		node_t operator+ (const node_t& other) const {
			node_t tmp = *this;
			tmp += other;
			return tmp;
		}
	};

	node_t a[2*MAXN];
	updater b[2*MAXN];

	void init() {
		for (int i=1; i<=MAXN; i++) {
			/* KOPIRAJ NEKI EKSTERNI NIZ OVDE */
			a[i + MAXN - 1] = node_t(0, 1);
		}
		for (int i=MAXN-1; i>0; i--) {
			a[i] = a[2*i] + a[2*i+1];
		}
	}

	void push(int i) {
		if (b[i]) {
			a[i] += b[i];
			if (i < MAXN) {
				b[2*i] += b[i];
				b[2*i+1] += b[i];
			}
			b[i] = updater();
		}
	}

	node_t get(int l, int r, int node=1, int nl=1, int nr=MAXN) {
		push(node);

		if (r < nl || nr < l) {
			return node_t();
		}
		if (l <= nl && nr <= r) {
			return a[node];
		}

		int nm = (nl + nr) >> 1;
		return get(l, r, 2*node, nl, nm) + get(l, r, 2*node+1, nm+1, nr);
	}

	void update(int l, int r, updater val, int node=1, int nl=1, int nr=MAXN) {
		push(node);

		if (r < nl || nr < l) {
			return;
		}
		if (l <= nl && nr <= r) {
			b[node] += val;
			push(node);
			return;
		}

		int nm = (nl + nr) >> 1;
		update(l, r, val, 2*node, nl, nm);
		update(l, r, val, 2*node+1, nm+1, nr);
		a[node] = a[2*node] + a[2*node+1];
	}
};

segtree_lazy<4 * 131072> drvo;


long long sol[300005];

struct upit {
	int l, r, id;

	bool operator< (const upit& other) const {
		return r < other.r;
	}
};

upit up[300005];
int prvi_put[300005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=m; i++) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}

	for (int i=1; i<=n; i++) {
		b[i] = new node(0);
	}

	for (int i=1; i<=n; i++) {
		rm[i] = rm[i-1];

		active_l = i;
		active_r = rm[i];

		while (1) {
			// probaj da dodas jos jedan cvor
			if (rm[i] < n) {
				++rm[i];
				active_r++;

				if (!add_node(rm[i])) {
					--rm[i];
					active_r--;
					break;
				}
			} else {
				break;
			}
		}
		remove_node(i);
		active_l++;
	}

	/*
	cerr << '\n';
	for (int i=1; i<=n; i++) {
		cerr << rm[i] << ' ';
	}
	cerr << '\n';
	*/
	drvo.init();

	int q;
	cin >> q;
	for (int i=1; i<=q; i++) {
		cin >> up[i].l >> up[i].r;
		up[i].id = i;
	}

	{
		int ptr = 0;
		for (int i=1; i<=n; i++) {
			while (ptr < rm[i]) {
				ptr++;
				prvi_put[ptr] = i;
			}
		}
		/*
		cerr << '\n';
		for (int i=1; i<=n; i++) {
			cerr << prvi_put[i] << ' ';
		}
		cerr << '\n';
		*/
	}

	sort(up+1, up+q+1);

	int qjj = 1;

	// resavam upite ciji je desni kraj i
	for (int i=1; i<=n; i++) {
		// prvo modifikujem strukturu
		drvo.update(prvi_put[i], i, 1);
		// cerr << "updating " << prvi_put[i] << ' ' << i << '\n';

		while (up[qjj].r == i) {
			// cerr << "solving " << up[qjj].id << '\n';

			sol[up[qjj].id] = drvo.get(up[qjj].l, n).x;
			qjj++;
		}
	}

	for (int i=1; i<=q; i++) {
		cout << sol[i] << '\n';
	}


}