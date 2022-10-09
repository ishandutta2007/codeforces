#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

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
		int x, id;

		/* CONSTRUCTOR */
		value(int x = 0, int id = 0) : x(x), id(id) {}

		value& operator+= (const value& other) {
			/* ADDITION */
			x += other.x;
			id = max(id, other.id);
			return *this;
		}

		value& operator+= (const updater& other) {
			/* UPDATE ADDITION */
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
			size = 1;
			left = right = parent = nullptr;
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
int a[100005];
node* b[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=n; i++)
		cin >> a[i];

	for (int i=0; i<=n; i++)
		b[i] = new node(value(1, i));

	for (int i=1; i<=n; i++) {
		if (i + a[i] <= n)
			link(b[i], b[i + a[i]]);
		else
			link(b[i], b[0]);
	}

	while (m--) {
		int t;
		cin >> t;
		if (t == 1) {
			int x;
			cin >> x;
			auto tmp = query(b[x], b[0]);
			cout << tmp.id << ' ' << tmp.x-1 << '\n';
		} else {
			int x, y;
			cin >> x >> y;
			if (x + a[x] <= n) {
				cut(b[x], b[x + a[x]]);
			} else {
				cut(b[x], b[0]);
			}

			a[x] = y;

			if (x + a[x] <= n) {
				link(b[x], b[x + a[x]]);
			} else {
				link(b[x], b[0]);
			}
		}
	}
}