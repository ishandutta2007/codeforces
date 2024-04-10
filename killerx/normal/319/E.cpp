#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 1e5 + 5;
int n, q;
int l[mxn], r[mxn], fa[mxn];

struct comp { bool operator() (int a, int b) { return l[a] < l[b]; } };
set <int, comp> top, son[mxn];

int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

void merge(int x, int y) {
	x = find(x); y = find(y);
	if (son[y].size() < son[x].size()) son[x].swap(son[y]);
	for (int s : son[x]) son[y].insert(s);
	fa[x] = y;
	l[y] = min(l[y], l[x]);
	r[y] = max(r[y], r[x]);
}

void chkson(int i, int x) {
	set <int, comp>::iterator it;
	l[n] = x;
	it = son[i].lower_bound(n);
	if (it != son[i].begin()) {
		-- it;
		if (r[*it] > x) {
			int j = *it;
			chkson(j, x);
			son[i].erase(j);
			merge(j, i);
		}
	}
}

int main() {
	scanf("%d", &q);
	while (q --) {
		int t, x, y;
		scanf("%d %d %d", &t, &x, &y);
		if (t == 1) {
			int i = n ++;
			fa[i] = i;
			int Left = -1, Right = -1;
			set <int, comp>::iterator it;
			l[i] = x;
			it = top.lower_bound(i);
			if (it != top.begin()) {
				-- it;
				if (r[*it] > x) Left = *it;
			}
			l[i] = y;
			it = top.lower_bound(i);
			if (it != top.begin()) {
				-- it;
				if (r[*it] > y) Right = *it;
			}
			l[i] = x; r[i] = y;
			if (Left != -1) {
				merge(Left, i);
				top.erase(Left);
			}
			if (Right != -1) {
				merge(Right, i);
				top.erase(Right);
			}
			l[n] = x;
			it = top.lower_bound(n);
			while (it != top.end() && r[*it] <= r[i]) {
				son[i].insert(*it);
				it = top.erase(it);
			}
			chkson(i, x);
			chkson(i, y);
			top.insert(i);
		}
		else {
			-- x; -- y;
			x = find(x); y = find(y);
			if (l[y] <= l[x] && r[x] <= r[y]) puts("YES");
			else puts("NO");
		}
	}
	return 0;
}

/*
5
1 1 5
1 5 11
2 1 2
1 2 9
2 1 2

*/