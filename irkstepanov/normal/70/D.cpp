
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cassert>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

struct pt {
	ll x, y;
	pt() {}
	pt(ll x, ll y) : x(x), y(y) {}
	pt operator-(const pt& other) const {
		return {x - other.x, y - other.y};
	}
};

ll cross(const pt& p, const pt& q) {
	return p.x * q.y - p.y * q.x;
}

mt19937 rr(1);

struct node {
	pt p;
	int pri;
	node* left;
	node* right;
	node(const pt& p) : p(p), pri(rr()), left(nullptr), right(nullptr) {}
};

void update(node* v) {
	/*if (v->left == nullptr) {
		v->link = nullptr;
	} else {
		v->link = v->left->link;
		if (v->link == nullptr) {
			v->link = v->left;
		}
	}*/
}

pair<node*, node*> split(node* v, ll key) { // < key go left
	if (v == nullptr) {
		return {nullptr, nullptr};
	}
	if (v->p.x >= key) {
		pair<node*, node*> p = split(v->left, key);
		v->left = p.second;
		update(v);
		return {p.first, v};
	} else {
		pair<node*, node*> p = split(v->right, key);
		v->right = p.first;
		update(v);
		return {v, p.second};
	}
}

node* merge(node* a, node* b) {
	if (a == nullptr) {
		return b;
	}
	if (b == nullptr) {
		return a;
	}
	if (a->pri > b->pri) {
		a->right = merge(a->right, b);
		update(a);
		return a;
	} else {
		b->left = merge(a, b->left);
		update(b);
		return b;
	}
}

node* geq(node* v, ll key) {
	if (v == nullptr) {
		return v;
	}
	if (v->p.x >= key) {
		node* ans = geq(v->left, key);
		return (ans == nullptr ? v : ans);
	} else {
		return geq(v->right, key);
	}
}

node* lt(node* v, ll key) {
	if (v == nullptr) {
		return v;
	}
	if (v->p.x < key) {
		node* ans = lt(v->right, key);
		return (ans == nullptr ? v : ans);
	} else {
		return lt(v->left, key);
	}
}

bool inside(const pt& q, node* v) {
	node* rg = geq(v, q.x);
	node* lf = lt(v, q.x);
	if (rg != nullptr && rg->p.x == q.x && rg->p.y >= q.y) {
		return true;
	}
	if (lf == nullptr || rg == nullptr) {
		return false;
	}
	return cross(q - lf->p, rg->p - lf->p) >= 0;
}

node* add(node* v, const pt& q) {
	if (v == nullptr) {
		return new node(q);
	}
	if (inside(q, v)) {
		return v;
	}
	node* rg = geq(v, q.x);
	node* lf = lt(v, q.x);
	if (rg != nullptr && rg->p.x == q.x) {
		rg = geq(v, rg->p.x + 1);
	}
	while (rg != nullptr) {
		node* nx = geq(v, rg->p.x + 1);
		if (nx == nullptr) {
			break;
		}
		if (cross(rg->p - q, nx->p - rg->p) >= 0) {
			rg = nx;
		} else {
			break;
		}
	}
	while (lf != nullptr) {
		node* pr = lt(v, lf->p.x);
		if (pr == nullptr) {
			break;
		}
		if (cross(lf->p - pr->p, q - lf->p) >= 0) {
			lf = pr;
		} else {
			break;
		}
	}
	pair<node*, node*> p1;
	if (rg == nullptr) {
		p1 = {v, nullptr};
	} else {
		p1 = split(v, rg->p.x);
	}
	pair<node*, node*> p2;
	if (lf == nullptr) {
		p2 = {nullptr, p1.first};
	} else {
		p2 = split(p1.first, lf->p.x + 1);
	}
	v = merge(p2.first, merge(new node(q), p1.second));
	return v;
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	//#ifdef LOCAL_DEFINE
		//freopen("input.txt", "r", stdin);
	//#endif
	
	node* upper = nullptr;
	node* lower = nullptr;

	int q;
	cin >> q;

	while (q--) {
		int tp;
		cin >> tp;
		pt p;
		cin >> p.x >> p.y;
		pt mp = {p.x, -p.y};
		if (tp == 1) {
			upper = add(upper, p);
			lower = add(lower, mp);
		} else {
			cout << (inside(p, upper) && inside(mp, lower) ? "YES\n" : "NO\n");
		}
	}

}