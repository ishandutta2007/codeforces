#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <deque>
#include <cassert>

using namespace std;

typedef long long ll;

ll INF = 1e18;
ll INFi = 2e9;
long double eps = 1e-6;
ll mod = 1e9 + 7;


int rnd() {
	return ((rand() << 15) + rand());
}


struct Node {
	int x, y, cnt;
	Node* L, * R;
	Node(int x_) {
		x = x_;
		cnt = 1;
		y = rnd();
		L = NULL;
		R = NULL;
	}
};

int cnt(Node* t) {
	if (t == NULL) return 0;
	else return t->cnt;
}

void upd_cnt(Node* t) {
	if (t == NULL) return;
	t->cnt = 1 + cnt(t->L) + cnt(t->R);
}

void print_tree(Node* t) {
	if (t == NULL) return;
	print_tree(t->L);
	cout << t->x << " ";
	print_tree(t->R);
}

pair<Node*, Node*> split(Node* t, int k) {
	if (t == NULL) {
		return { NULL, NULL };
	}
	if (t->x < k) {
		auto f = split(t->R, k);
		t->R = f.first;
		upd_cnt(t->R);
		upd_cnt(f.second);
		return { t, f.second };
	}
	else {
		auto f = split(t->L, k);
		t->L = f.second;
		upd_cnt(t->L);
		upd_cnt(f.first);
		return { f.first, t };
	}
}

Node* merge(Node* left, Node* right) {
	if (left == NULL) return right;
	if (right == NULL) return left;
	upd_cnt(left);
	upd_cnt(right);
	if (left->y > right->y) {
		left->R = merge(left->R, right);
		upd_cnt(left);
		return left;
	}
	else {
		right->L = merge(left, right->L);
		upd_cnt(right);
		return right;
	}
}

Node* insert(Node* t, int k) {
	auto f = split(t, k);
	return merge(merge(f.first, new Node(k)), f.second);
}

Node* remove(Node* t, int k) {
	if (t == NULL) return NULL;
	if (k < t->x) {
		t->L = remove(t->L, k);
		upd_cnt(t->L);
	}
	else if (k > t->x) {
		t->R = remove(t->R, k);
		upd_cnt(t->R);
	}
	else {
		t = merge(t->L, t->R);
	}
	upd_cnt(t);
	return t;
}

bool exist(Node* t, int k) {
	if (t == NULL) return false;
	if (t->x == k) return true;
	if (t->x < k) return exist(t->R, k);
	return exist(t->L, k);
}

ll next(Node* t, int k) {
	auto f = split(t, k + 1);
	Node* h = f.second;
	ll ans = -INF;
	if (h == NULL) ans = INF;
	while (ans != INF && h->L != NULL) h = h->L;
	if (h != NULL) ans = max(ans, (ll)h->x);
	t = merge(f.first, f.second);
	upd_cnt(t);
	return ans;
}

ll prev(Node* t, int k) {
	auto f = split(t, k);
	Node* h = f.first;
	ll ans = -INF;
	if (h == NULL) ans = INF;
	while (ans != INF && h->R != NULL) h = h->R;
	if (h != NULL) ans = max(ans, (ll)h->x);
	t = merge(f.first, f.second);
	upd_cnt(t);
	return ans;
}

ll kth(Node* t, int k) {
	if (t == NULL) return INF;
	if (cnt(t->L) == k - 1) return t->x;
	if (cnt(t->L) >= k) return kth(t->L, k);
	return kth(t->R, k - 1 - cnt(t->L));
}




int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cout.precision(15);

	int n, m, q;
	cin >> n >> m >> q;
	vector<ll> a(n);
	vector<pair<ll, int>> cit(m);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cit[a[i] - 1].first++;
	}
	for (int i = 0; i < m; i++) cit[i].second = i;
	sort(cit.begin(), cit.end());
	vector<ll> pref(m + 1);
	for (int i = 0; i < m; i++) {
		pref[i + 1] = pref[i] + cit[i].first;
	}
	vector<ll> need(m);
	for (ll i = 0; i < m; i++) {
		need[i] = cit[i].first * i - pref[i];
		//cout << need[i] << " ";
	}
	//cout << endl;
	ll t;
	int ind = 0;
	Node* root = NULL;
	vector<pair<ll, int>> qu(q);
	vector<ll> ans(q);
	for (pair<ll, int>& i : qu) cin >> i.first;
	for (int i = 0; i < q; i++) qu[i].second = i;
	sort(qu.begin(), qu.end());
	for(int i = 0; i < q; i++) {
		pair<ll, int> t = qu[i]; t.first -= n;
		ll k = lower_bound(need.begin(), need.end(), t.first) - need.begin();
		while (ind < k) {
			//cout << cit[ind].second << " flex\n";
			root = insert(root, cit[ind].second);
			upd_cnt(root);
			ind++;
		}
		k--;
		//cout << k << endl;
		t.first -= need[k];
		t.first = (t.first % (k + 1) + k) % (k + 1);
		//cout << t << endl;
		//print_tree(root);
		//cout << endl;
		ans[t.second] = kth(root, t.first + 1) + 1;
	}
	for (ll i : ans) cout << i << endl;
	return 0;
}