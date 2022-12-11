/*************************************************************************
    > File Name: E.cpp
    > Author: wmg_1001
    > Mail: wmg_1007@163.com 
    > Created Time: 20141007  003949
 ************************************************************************/

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <deque>
#include <queue>
#include <map>
#include <set>
using namespace std;

typedef long long LL;

const int maxn = 100005;

struct Node {
	LL h;
	int pos;
}L[maxn], tmp_L[maxn];
struct tree_node {
	int l, r;
	int maxx;
}tree[maxn * 4];

int F[maxn], last[maxn], Left[maxn], Right[maxn];
LL H[maxn];

bool operator < (const Node &a, const Node &b) {
	if (a.h == b.h) return a.pos < b.pos;
	return a.h < b.h;
}

int n;
LL d;

void build_tree(int p, int l, int r) {
	tree[p].l = l;
	tree[p].r = r;
	tree[p].maxx = -1;
	if (tree[p].l == tree[p].r) return ;
	int mid = (tree[p].l + tree[p].r) >> 1;
	int lson = (p << 1), rson = (p << 1) + 1;
	build_tree(lson, l, mid);
	build_tree(rson, mid + 1, r);
}

void maintain(int p) {
	int lson = (p << 1), rson = (p << 1) + 1;
	if (tree[lson].maxx == -1 && tree[rson].maxx != -1) tree[p].maxx = tree[rson].maxx;
	if (tree[lson].maxx != -1 && tree[rson].maxx == -1) tree[p].maxx = tree[lson].maxx;
	if (tree[lson].maxx != -1 && tree[rson].maxx != -1) {
		if (F[tree[lson].maxx] < F[tree[rson].maxx]) tree[p].maxx = tree[rson].maxx;
		else tree[p].maxx = tree[lson].maxx;
	}
}

void insert_tree(int p, int u, int v) {
	if (tree[p].l == tree[p].r) {
		if (tree[p].maxx == -1) tree[p].maxx = v;
		else {
			if (F[tree[p].maxx] < F[v]) tree[p].maxx = v;
		}
		return ;
	}
	int mid = (tree[p].l + tree[p].r) >> 1;
	int lson = (p << 1), rson = (p << 1) + 1;
	if (u > mid) insert_tree(rson, u, v);
	else insert_tree(lson, u, v);
	maintain(p);
}

int find_tree(int p, int l, int r) {
	if (l > r) return -1;
	if (tree[p].l == l && tree[p].r == r) return tree[p].maxx;
	int mid = (tree[p].l + tree[p].r) >> 1;
	int lson = (p << 1), rson = (p << 1) + 1;
	if (l > mid) return find_tree(rson, l, r);
	else {
		if (r <= mid) return find_tree(lson, l, r);
		else {
			int t1 = find_tree(lson, l, mid);
			int t2 = find_tree(rson, mid + 1, r);
			if (t1 == -1) return t2;
			if (t2 == -1) return t1;
			if (F[t1] > F[t2]) return t1;
			else return t2;
		}
	}
	return -1;
}

int main() {
	cin >> n >> d;
	for (int i = 0; i < n; i++) {
		cin >> L[i].h;
		H[i] = L[i].h;
		L[i].pos = i;
	}
	sort(L, L + n);
	build_tree(1, 0, n - 1);
	for (int i = 0; i < n; i++) {
		Node tmp;
		tmp.h = H[i] + d;
		tmp.pos = 0;
		Right[i] = lower_bound(L, L + n, tmp) - L;
	}
	for (int i = 0; i < n; i++) {
		tmp_L[i] = L[n - 1 - i];
		tmp_L[i].h = -L[n - 1 - i].h;
	}
	for (int i = 0; i < n; i++) {
		Node tmp;
		tmp.h = -H[i] + d;
		tmp.pos = 0;
		Left[i] = lower_bound(tmp_L, tmp_L + n, tmp) - tmp_L;
		Left[i] = n - 1 - Left[i];
	}
	memset(F, 0, sizeof(F));
	for (int i = n - 1; i >= 0; i--) {
		int r1 = find_tree(1, 0, Left[i]);
		int r2 = find_tree(1, Right[i], n - 1);
		int r = r1;
		if (r2 != -1 && (r1 == -1 || F[r1] < F[r2])) r = r2;
		if (r == -1) {
			F[i] = 1;
			last[i] = -1;
		} else {
			F[i] = 1 + F[r];
			last[i] = r;
		}
		Node tmp;
		tmp.h = H[i]; tmp.pos = i;
		insert_tree(1, lower_bound(L, L + n, tmp) - L, i);
	}
	int res = 0;
	for (int i = 0; i < n; i++) res = max(res, F[i]);
	cout << res << endl;
	for (int i = 0; i < n; i++) {
		if (F[i] == res) {
			int p = i;
			while (p != -1) {
				if (last[p] == -1) printf("%d\n", p + 1);
				else printf("%d ", p + 1);
				p = last[p];
			}
			break;
		}
	}
	return 0;
}