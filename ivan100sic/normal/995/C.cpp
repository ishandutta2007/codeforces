#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct pt {
	int x, y, f, i;
	ll len() const {
		return x*1ll*x + y*1ll*y;
	}
	void flip() {
		x *= -1;
		y *= -1;
		f *= -1;
	}
	pt operator- () const {
		return {-x, -y, -f};
	}
};

const ll UB = 1'000'000'000'000ll;

pt sum(const vector<pt>& v) {
	ll x = 0, y = 0;
	for (pt p : v) {
		x += p.x;
		y += p.y;
	}
	return {(int)x, (int)y};
}

int ans[100005];

struct node {
	pt z;
	node* l;
	node* r;
	int f;

	node() {}

	node(int x, int y, int i) {
		z = {x, y, 1, i};
		l = r = nullptr;
		f = 1;
	}

	void flip() {
		f *= -1;
		z.x *= -1;
		z.y *= -1;
		z.f *= -1;
	}

	node(node* u, node* v) {
		z = sum({u->z, v->z});
		l = u;
		r = v;
		f = 1;
	}
};

node* root1 = nullptr, *root2 = nullptr;

pair<node*, node*> spoji(node* a, node* b, node* c) {
	if (sum({a->z, b->z}).len() <= UB)
		return {new node(a, b), c};
	if (sum({a->z, c->z}).len() <= UB)
		return {new node(a, c), b};
	if (sum({b->z, c->z}).len() <= UB)
		return {new node(b, c), a};

	if (sum({a->z, -b->z}).len() <= UB) {
		b->flip();
		return {new node(a, b), c};
	}

	if (sum({a->z, -c->z}).len() <= UB) {
		c->flip();
		return {new node(a, c), b};
	}

	if (sum({b->z, -c->z}).len() <= UB) {
		c->flip();
		return {new node(b, c), a};
	}

	return {nullptr, nullptr};
}

node* spoji(node* a, node* b) {
	if (sum({a->z, -b->z}).len() <= sum({a->z, b->z}).len())
		b->flip();
	return new node(a, b);
}

void dfs(node* x) {
	if (x->l) {
		if (x->f == -1) {
			x->l->flip();
			x->r->flip();
		}
		dfs(x->l);
		dfs(x->r);
	} else {
		ans[x->z.i] = x->f;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	vector<pt> v;
	int n;
	cin >> n;
	for (int i=0; i<n; i++) {
		int x, y;
		cin >> x >> y;
		if (!root1)
			root1 = new node(x, y, i);
		else if (!root2)
			root2 = new node(x, y, i);
		else {
			node* tmp = new node(x, y, i);
			auto r = spoji(root1, root2, tmp);
			root1 = r.first;
			root2 = r.second;
		}
	}

	node* root = nullptr;

	if (!root2) {
		root = root1;
	} else {
		root = spoji(root1, root2);
	}
	
	dfs(root);

	for (int i=0; i<n; i++)
		cout << ans[i] << ' ';
}