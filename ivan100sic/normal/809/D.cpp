#include <bits/stdc++.h>
using namespace std;

namespace treap_ns {

	struct updater {
		/* DATA MEMBERS */
		int x;

		updater(int x = 0) : x(x) {}

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

	struct element {
		/* DATA MEMBERS */
		int key, size;

		/* CONSTRUCTOR */
		element(int x) : key(x), size(1) {}

		element() : key(0), size(0) {}

		element& operator+= (const element& other) {
			/* ADDITION */
			size += other.size;

			return *this;
		}

		element& operator+= (const updater& other) {
			/* UPDATE ADDITION */
			key += other.x;

			return *this;
		}

		element operator+ (const element& other) const {
			element tmp = *this;
			tmp += other;
			return tmp;
		}
	};

	typedef unsigned int priority_t;

	priority_t new_priority() {
		static priority_t x = 329030921;
		return x += 1111111111;
	}

	struct treap {
		treap* left;
		treap* right;

		element data, total;
		updater update;
		priority_t priority;

		treap (element data = element()) : left(nullptr), right(nullptr),
			data(data), total(data), update(), priority(new_priority()) {}
	};

	void push(treap* node) {
		if (!node) {
			return;
		}

		if (!node->update) {
			// nothing to do
			return;
		}

		node->data += node->update;
		node->total += node->update;

		if (node->left) node->left->update += node->update;
		if (node->right) node->right->update += node->update;

		node->update = updater();
	}

	void recompute(treap* node) {
		if (!node) {
			return;
		}

		if (node->left) {
			node->total = node->left->total;
		} else {
			node->total = element();
		}

		node->total += node->data;
		if (node->right) {
			node->total += node->right->total;
		}
	}

	/*
		split prima kao parametar cvor na kome se treap splituje i
		objekat funkcije kome se prosledjuje pokazivac na cvor, a on
		treba da vrati true ukoliko root treba da bude deo levog parceta
		splita, a false inace.

		Ideja je da Funktor bude objekat koji moze da se apdejtuje odnosno
		da prilagodi svoj kriterijum za secenje, npr da bi se podrzao
		upit secenja po velicini. Funktor treba da aptejtuje svoj kriterijum
		nakon poziva f()
	*/
	template<class Functor>
	void split(treap* node, Functor f, treap*& lt, treap*& rt) {
		if (!node) {
			lt = rt = nullptr;
			return;
		}

		push(node);

		if (f(node)) {
			split(node->right, f, node->right, rt);
			push(node->left);
			lt = node;
		} else {
			split(node->left, f, lt, node->left);
			push(node->right);
			rt = node;
		}

		recompute(node);
	}

	treap* merge(treap* l, treap* r) {
		if (!l) {
			push(r);
			return r;
		}

		if (!r) {
			push(l);
			return l;
		}

		treap* node;

		if (l->priority > r->priority) {
			push(l);
			l->right = merge(l->right, r);
			node = l;
		} else {
			push(r);
			r->left = merge(l, r->left);
			node = r;
		}

		recompute(node);
		return node;
	}

	void destroy(treap* node) {
		if (!node) {
			return;
		}
		destroy(node->left);
		destroy(node->right);
		delete node;
	}

	// various useful splitters

	struct leftmost_splitter {
		bool done;

		leftmost_splitter() : done(false) {}

		bool operator() (treap* node) {
			if (done) {
				return false;
			} else {
				if (node->left) {
					return false;
				} else {
					return done = true;
				}
			}
		}
	};

	struct key_less_splitter {
		int key;

		key_less_splitter(int key) : key(key) {}

		bool operator() (treap* node) {
			return node->data.key < key;
		}
	};
}

using namespace treap_ns;

// KRAJ TEMPLATE KODA
void print_inorder(treap* root) {
	if (!root) {
		return;
	}
	push(root);

	print_inorder(root->left);
	cerr << root->data.key << ' ';
	print_inorder(root->right);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;

	auto root = new treap(0);

	while (n--) {
		int l, r;
		cin >> l >> r;
		treap* left_part, *middle_part, *right_part, *temp;

		split(root, key_less_splitter(l), left_part, temp);
		split(temp, key_less_splitter(r), middle_part, right_part);

		if (right_part) {
			treap* a, *b;
			split(right_part, leftmost_splitter(), a, b);
			destroy(a);
			right_part = b;
		}

		if (middle_part) {
			middle_part->update += updater(1);
		}

		auto tooth = new treap(l);

		root = merge(merge(left_part, tooth), merge(middle_part, right_part));

		// print_inorder(root);
		// cerr << '\n';
	}

	cout << root->total.size - 1 << '\n';	
}