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

const ll inf0 = 2 * 1024 * 1024 * 1023;
const ll inf = inf0 * inf0;
double eps = 1e-6;
ll mod = 1e9 + 7;

int l = 20;


struct Line {
	ll k, b;
	Line() {}
	Line(ll _k, ll _b) : k(_k), b(_b) {}
	ll get(ll x) { return k * x + b; }
};

struct Node {
	Line a;
	Node* L = NULL, * R = NULL;
	Node() {}
	Node(Line _a) : a(_a) {}
	Node(Line _a, Node* _L, Node* _R) : a(_a), L(_L), R(_R) {}
};

void add(Node* v, ll l,ll r, Line f) {
	ll m = (r + l) / 2;
	bool lef = f.get(l) < v->a.get(l);
	bool mid = f.get(m) < v->a.get(m);
	if (mid) swap(v->a, f);
	if (r - l == 1) return;
	if (mid != lef) {
		if (v->L == NULL) v->L = new Node({ 0, inf });
		add(v->L, l, m, f);
	}
	else {
		if (v->R == NULL) v->R = new Node({ 0, inf });
		add(v->R, m, r, f);
	}
}

ll get(Node* v, ll l, ll r, ll x) {
	if (v == NULL) return inf;
	if (r - l == 1) return v->a.get(x);
	ll m = (l + r) / 2;
	if (x < m) return min(v->a.get(x), get(v->L, l, m, x));
	return min(v->a.get(x), get(v->R, m, r, x));
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<ll> b(n);
	for (int i = 0; i < n; i++) cin >> b[i];
	vector<ll> dp(n);
	Node* cht = new Node({ 0, inf });
	dp[0] = 0;
	add(cht, 0, inf0, { b[0], dp[0] });
	for (int i = 1; i < n; i++) {
		dp[i] = get(cht, 0, inf0, a[i]);
		add(cht, 0, inf0, { b[i], dp[i] });
	}
	cout << dp[n - 1] << endl;
	return 0;
}