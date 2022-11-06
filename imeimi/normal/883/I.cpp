#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <functional>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<llong, llong> pll;

struct node {
	node *l, *r;
	int key, val1, max1, val2, max2, rnd;
	node() {}
	node(int key, int val1, int val2)
		: l(0), r(0), key(key), val1(val1), max1(val1), val2(val2), max2(val2), rnd(rand()) {}
} ns[300000];

void update(node * x) {
	x->max1 = x->val1;
	x->max2 = x->val2;
	if (x->l) {
		x->max1 = max(x->l->max1, x->max1);
		x->max2 = min(x->l->max2, x->max2);
	}
	if (x->r) {
		x->max1 = max(x->r->max1, x->max1);
		x->max2 = min(x->r->max2, x->max2);
	}
}

node * merge(node * a, node * b) {
	if (!a || !b) return a ? a : b;
	if (a->rnd < b->rnd) {
		a->r = merge(a->r, b);
		update(a);
		return a;
	}
	else {
		b->l = merge(a, b->l);
		update(b);
		return b;
	}
}

void split(node * x, node * &a, node * &b, int k) {
	if (!x) {
		a = b = 0;
		return;
	}
	if (x->key < k) {
		a = x;
		split(x->r, a->r, b, k);
		update(a);
	}
	else {
		b = x;
		split(x->l, a, b->l, k);
		update(b);
	}
}

int n, k;
int v[300000];
int dp[300000];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	srand((unsigned int)time(0));
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	sort(v, v + n);
	for (int i = k - 1; i < 2 * k - 1; ++i) {
		dp[i] = v[i] - v[0];
	}
	node * rt = 0;
	node *a, *b;
	for (int i = 2 * k - 1; i < n; ++i) {
		int j = i - k;
		node * x = ns + i;
		ns[i] = node(dp[j] + v[j + 1], j, dp[j]);
		split(rt, a, b, x->key);
		rt = merge(a, merge(x, b));
		split(rt, a, b, v[i]);
		dp[i] = 2e9;
		if (a) {
			dp[i] = min(dp[i], v[i] - v[a->max1 + 1]);
		}
		if (b) {
			dp[i] = min(dp[i], b->max2);
		}
		rt = merge(a, b);
	}
	printf("%d\n", dp[n - 1]);
	return 0;
}