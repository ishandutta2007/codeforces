#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

mt19937 rr(random_device{}());
const int inf = 1e9;

struct node {
	int key;
	int size;
	int pri;
	int minn;
	node* left;
	node* right;
	node(int val) : key(val), size(1), pri(rr()), minn(val), left(nullptr), right(nullptr) {}
};

int getSize(node* v) {
	return (v == nullptr ? 0 : v->size);
}

int getMinn(node* v) {
	return (v == nullptr ? inf : v->minn);
}

void update(node* v) {
	v->size = 1 + getSize(v->left) + getSize(v->right);
	v->minn = min(v->key, min(getMinn(v->left), getMinn(v->right)));
}

ll ans = 0;

pair<node*, node*> splitByMinn(node* v) {
	if (v == nullptr) {
		return {nullptr, nullptr};
	}
	if (getMinn(v->left) == v->minn) {
		pair<node*, node*> p = splitByMinn(v->left);
		v->left = p.second;
		update(v);
		return {p.first, v};
	} else if (v->key == v->minn) {
		ans += getSize(v->left) + 1;
		return {v->left, v->right};
	} else {
		pair<node*, node*> p = splitByMinn(v->right);
		v->right = p.first;
		update(v);
		ans += getSize(v->left) + 1;
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

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//ifstream cin("input.txt");

	int n;
	cin >> n;

	node* root = nullptr;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		root = merge(root, new node(x));
	}

	for (int i = 0; i < n; ++i) {
		pair<node*, node*> p = splitByMinn(root);
		root = merge(p.second, p.first);
		//cout << ans << "\n";
	}

	cout << ans << "\n";

}