#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define sz(a) (int)(a).size()
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;
mt19937 rr(random_device{}());

struct node {
	int key;
	int val;
	ll sum;
	int pri;
	node* left;
	node* right;
	node() {}
	node(int key, int val) : key(key), val(val), sum(val - key), pri(rr()), left(nullptr), right(nullptr) {}
	node(int key, int val, int pri) : key(key), val(val), sum(val - key), pri(pri), left(nullptr), right(nullptr) {}
};

ll getSum(node* v) {
	if (v == nullptr) {
		return 0;
	}
	return v->sum;
}

void update(node* v) {
	v->sum = ll(v->val - v->key) + getSum(v->left) + getSum(v->right);
}

pair<node*, node*> split(node* v, int key) {
	if (v == nullptr) {
		return {nullptr, nullptr};
	}
	if (v->key <= key) {
		pair<node*, node*> p = split(v->right, key);
		v->right = p.first;
		update(v);
		return {v, p.second};
	} else {
		pair<node*, node*> p = split(v->left, key);
		v->left = p.second;
		update(v);
		return {p.first, v};
	}
}

pair<node*, node*> split(node* v, int key, int val) {
	if (v == nullptr) {
		return {nullptr, nullptr};
	}
	if (v->key < key || (v->key == key && v->val <= val)) {
		pair<node*, node*> p = split(v->right, key, val);
		v->right = p.first;
		update(v);
		return {v, p.second};
	} else {
		pair<node*, node*> p = split(v->left, key, val);
		v->left = p.second;
		update(v);
		return {p.first, v};
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

vector<node*> t;

int getPrev(int a, int place, const vector<set<int> >& pos, int n) {
	set<int>::iterator it = pos[a].lower_bound(place);
	if (it == pos[a].begin()) {
		return n;
	} else {
		return *(--it);
	}
}

void build(int v, int tl, int tr, const vector<int>& a, const vector<set<int> >& pos, int n) {
	if (tl == tr) {
		t[v] = new node(getPrev(a[tl], tl, pos, -1), tl);
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v * 2, tl, tm, a, pos, n);
	build(v * 2 + 1, tm + 1, tr, a, pos, n);
	vector<pii> pr;
	for (int i = tl; i <= tr; ++i) {
		pr.pb({getPrev(a[i], i, pos, -1), i});
	}
	sort(all(pr));
	for (int i = 0; i < sz(pr); ++i) {
		t[v] = merge(t[v], new node(pr[i].first, pr[i].second));
	}
}

node* erase(node* v, int key, int val) {
	if (v->key == key && v->val == val) {
		v = merge(v->left, v->right);
		return v;
	}
	if ((v->key > key) || (v->key == key && v->val > val)) {
		v->left = erase(v->left, key, val);
		update(v);
		return v;
	} else {
		v->right = erase(v->right, key, val);
		update(v);
		return v;
	}
}

node* insert(node* v, int key, int val, int pri) {
	if (v == nullptr) {
		v = new node(key, val, pri);
		return v;
	}
	if (v->pri > pri) {
		if (v->key > key || (v->key == key && v->val > val)) {
			v->left = insert(v->left, key, val, pri);
			update(v);
			return v;
		} else {
			v->right = insert(v->right, key, val, pri);
			update(v);
			return v;
		}
	} else {
		pair<node*, node*> p = split(v, key, val);
		node* u = new node(key, val, pri);
		u->left = p.first;
		u->right = p.second;
		update(u);
		return u;
	}
}

void erase(int v, int tl, int tr, int pos, int a, int b) {
	t[v] = erase(t[v], a, b);
	if (tl == tr) {
		return;
	}
	int tm = (tl + tr) >> 1;
	if (pos <= tm) {
		erase(v * 2, tl, tm, pos, a, b);
	} else {
		erase(v * 2 + 1, tm + 1, tr, pos, a, b);
	}
}


void insert(int v, int tl, int tr, int pos, int a, int b) {
	t[v] = insert(t[v], a, b, rr());
	if (tl == tr) {
		return;
	}
	int tm = (tl + tr) >> 1;
	if (pos <= tm) {
		insert(v * 2, tl, tm, pos, a, b);
	} else {
		insert(v * 2 + 1, tm + 1, tr, pos, a, b);
	}
}


ll solve(int v, int tl, int tr, int l, int r, int ql) {
	if (l == tl && r == tr) {
		ll ans = getSum(t[v]);
		pair<node*, node*> p = split(t[v], ql - 1);
		ans -= getSum(p.first);
		t[v] = merge(p.first, p.second);
		return ans;
	}
	ll ans = 0;
	int tm = (tl + tr) >> 1;
	if (l <= tm) {
		ans += solve(v * 2, tl, tm, l, min(r, tm), ql);
	}
	if (r > tm) {
		ans += solve(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, ql);
	}
	return ans;
}

/*void out(node* v) {
	if (v == nullptr) {
		return;
	}
	out(v->left);
	cout << v->key << " " << v->val << "\n";
	out(v->right);
}*/

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

	int n, q;
	//n = int(1e5);
	//q = 1;

	cin >> n >> q;

	vector<int> a(n);
	vector<set<int> > pos(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		//a[i] = rr() % 100 + 1;
		--a[i];
		pos[a[i]].insert(i);
	}

	t.assign(4 * n, nullptr);
	build(1, 0, n - 1, a, pos, n);

	while (q--) {
		int type;
		cin >> type;
		//type = 2;
		//type = rr() % 2;
		if (type == 1) {
			int place;
			int x;
			cin >> place >> x;
			//place = rr() % n + 1;
			//x = rr() % 100 + 1;
			--place, --x;
			int val = a[place];
			if (val == x) {
				continue;
			}
			set<int>::iterator it = pos[val].lower_bound(place);
			if (it == pos[val].begin() && it == --pos[val].end()) {
				erase(1, 0, n - 1, place, -1, place);
			} else if (it == pos[val].begin()) {
				set<int>::iterator nx = it;
				++nx;
				erase(1, 0, n - 1, place, -1, place);
				erase(1, 0, n - 1, *nx, place, *nx);
				insert(1, 0, n - 1, *nx, -1, *nx);
			} else if (it == --pos[val].end()) {
				set<int>::iterator pr = it;
				--pr;
				erase(1, 0, n - 1, place, *pr, place);
			} else {
				set<int>::iterator nx = it;
				++nx;
				set<int>::iterator pr = it;
				--pr;
				erase(1, 0, n - 1, place, *pr, place);
				erase(1, 0, n - 1, *nx, place, *nx);
				insert(1, 0, n - 1, *nx, *pr, *nx);
			}
			pos[val].erase(place);

			a[place] = x;
			pos[x].insert(place);
			it = pos[x].lower_bound(place);
			if (it == pos[x].begin() && it == --pos[x].end()) {
				insert(1, 0, n - 1, place, -1, place);
			} else if (it == pos[x].begin()) {
				set<int>::iterator nx = it;
				++nx;
				erase(1, 0, n - 1, *nx, -1, *nx);
				insert(1, 0, n - 1, *nx, place, *nx);
				insert(1, 0, n - 1, place, -1, place);
			} else if (it == --pos[x].end()) {
				set<int>::iterator pr = it;
				--pr;
				insert(1, 0, n - 1, place, *pr, place);
			} else {
				set<int>::iterator pr = it;
				--pr;
				set<int>::iterator nx = it;
				++nx;
				erase(1, 0, n - 1, *nx, *pr, *nx);
				insert(1, 0, n - 1, *nx, place, *nx);
				insert(1, 0, n - 1, place, *pr, place);
			}
		} else {
			int l, r;
			cin >> l >> r;
			//l = rr() % n + 1;
			//r = rr() % n + 1;
			//l = 1, r = n;
			if (l > r) {
				swap(l, r);
			}
			--l, --r;
			ll ans = solve(1, 0, n - 1, l, r, l);
			cout << ans << "\n";
		}
	}

}