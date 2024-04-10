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
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <random>

using namespace std;

typedef long long ll;

ll INF = 1e18;
int INFi = 2e9;
double eps = 1e-8;
ll mod = 1e9 + 7;
int p = 47;

ll rnd() {
	return (rand() << 15) + rand();
}

struct Node {
	ll r, x, y, maxi, maxind, ind;
	Node *L, *R;
	Node() {}
	Node(ll _r, ll _x, ll _ind) : r(_r), x(_x), y(rnd()), ind(_ind), maxi(_x), L(NULL), R(NULL), maxind(_ind) {}
};

ll get_maxi(Node *root) {
	if (root == NULL) return -INFi;
	return root->maxi;
}

void upd_maxi(Node *&root) {
	if (root == NULL) return;
	if (get_maxi(root->L) >= get_maxi(root->R) && get_maxi(root->L) >= root->x) {
		root->maxi = get_maxi(root->L);
		root->maxind = root->L->maxind;
	}
	else if (root->x >= get_maxi(root->L) && root->x >= get_maxi(root->R)) {
		root->maxi = root->x;
		root->maxind = root->ind;
	}
	else {
		root->maxi = get_maxi(root->R);
		root->maxind = root->R->maxind;
	}
}

Node* merge(Node *left, Node *right) {
	if (left == NULL) return right;
	if (right == NULL) return left;
	upd_maxi(left);
	upd_maxi(right);
	if (left->y > right->y) {
		left->R = merge(left->R, right);
		upd_maxi(left);
		return left;
	}
	else {
		right->L = merge(left, right->L);
		upd_maxi(right);
		return right;
	}
}


pair<Node*, Node*> split(Node *t, ll k) {
	if (t == NULL) return { NULL, NULL };
	if (t->r < k) {
		auto f = split(t->R, k);
		t->R = f.first;
		upd_maxi(t->R);
		upd_maxi(f.second);
		return { t, f.second };
	}
	else {
		auto f = split(t->L, k);
		t->L = f.second;
		upd_maxi(t->L);
		upd_maxi(f.first);
		return { f.first, t };
	}
}

Node *insert(Node *root, ll r, ll k, ll ind) {
	auto f = split(root, r);
	return merge(merge(f.first, new Node(r, k, ind)), f.second);
}

pair<ll, ll> max_less(Node *root, ll k) {
	if (root == NULL) return { -INFi, -INFi };
	//cout << root->ind << " " << root->r << endl;
	if (root->r <= k) {
		auto f = max_less(root->R, k);
		if (f.first >= get_maxi(root->L) && f.first >= root->x) {
			return f;
		}
		else if (root->x >= get_maxi(root->L) && root->x >= f.first) {
			return { root->x, root->ind };
		}
		else {
			//cout << "seax " << root->L->ind << " " << root->ind << endl;
			//if (root->L->ind == 6) cout << root->L->maxi << " " << root->L->maxind << endl;
			return { get_maxi(root->L), root->L->maxind };
		}
	}
	else {
		return max_less(root->L, k);
	}
}

pair<ll, ll> max_more(Node *root, ll k) {
	if (root == NULL) return { -INFi, -INFi };
	if (root->r >= k) {
		auto f = max_more(root->L, k);
		if (f.first >= get_maxi(root->R) && f.first >= root->x) {
			return f;
		}
		else if (root->x >= get_maxi(root->R) && root->x >= f.first) {
			return { root->x, root->ind };
		}
		else {
			return { get_maxi(root->R), root->R->maxind };
		}
	}
	else {
		return max_more(root->R, k);
	}
}

void prll_tree(Node *t) {
	if (t == NULL) return;
	prll_tree(t->L);
	cout << t->r << " ";
	prll_tree(t->R);
}


int main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	ll n, d;
	cin >> n >> d;
	vector<ll> a(n);
	for (ll i = 0; i < n; i++) cin >> a[i];
	vector<ll> dp(n, 1);
	vector<ll> p(n, -1);
	Node *root = NULL;
	for (ll i = 0; i < n; i++) {
		auto f1 = max_less(root, a[i] - d);
		auto f2 = max_more(root, a[i] + d);
		//cout << " --- " << i << endl;
		//cout << f1.first << " " << f1.second << " " << f2.first << " " << f2.second << endl;
		if (f1.first != -INFi || f2.first != -INFi) {
			if (f1.first >= f2.first) {
				dp[i] = f1.first + 1;
				p[i] = f1.second;
			}
			else {
				dp[i] = f2.first + 1;
				p[i] = f2.second;
			}
		}
		root = insert(root, a[i], dp[i], i);
		upd_maxi(root);
		//prll_tree(root);
		//cout << endl;
		//cout << dp[i] << endl;
	}
	ll ind = 0;
	for (ll i = 1; i < n; i++) {
		if (dp[i] > dp[ind]) {
			ind = i;
		}
	}
	cout << dp[ind] << endl;
	vector<ll> ans;
	while (ind != -1) {
		ans.push_back(ind);
		ind = p[ind];
	}
	reverse(ans.begin(), ans.end());
	for (ll i : ans) cout << i + 1 << " ";
	cout << endl;
	//system("pause");
	return 0;
}