#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 1e5 + 10;

int n, q, ans[26], sz[N << 2][26], tag[N << 2], len[N << 2];
char s[N];

void pu(int u) {
	for(int i = 0; i < 26; i ++) {
		sz[u][i] = sz[u << 1][i] + sz[u << 1 | 1][i];
	}
}

void clr(int u) {
	for(int i = 0; i < 26; i ++) sz[u][i] = 0;
}

void pd(int u) {
	if(~ tag[u]) {
		tag[u << 1] = tag[u << 1 | 1] = tag[u];
		clr(u << 1); sz[u << 1][tag[u]] = len[u << 1];
		clr(u << 1 | 1); sz[u << 1 | 1][tag[u]] = len[u << 1 | 1];
		tag[u] = -1;
	}
}

void build(int u, int l, int r) {
	tag[u] = -1; len[u] = r - l + 1;
	if(l == r) {
		sz[u][s[l] - 'a'] = 1;
		return ;
	}
	int mid = (l + r) >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
	pu(u);
}

void upd(int u, int l, int r, int ql, int qr, int x) {
	if(l == ql && r == qr) {
		clr(u); sz[u][x] = len[u]; tag[u] = x;
		return ;
	}
	int mid = (l + r) >> 1; pd(u);
	if(qr <= mid) upd(u << 1, l, mid, ql, qr, x);
	else if(ql > mid) upd(u << 1 | 1, mid + 1, r, ql, qr, x);
	else {
		upd(u << 1, l, mid, ql, mid, x);
		upd(u << 1 | 1, mid + 1, r, mid + 1, qr, x);
	}
	pu(u);
}

void qry(int u, int l, int r, int ql, int qr) {
	if(l == ql && r == qr) {
		for(int i = 0; i < 26; i ++) ans[i] += sz[u][i];
		return ;
	}
	int mid = (l + r) >> 1; pd(u);
	if(qr <= mid) qry(u << 1, l, mid, ql, qr);
	else if(ql > mid) qry(u << 1 | 1, mid + 1, r, ql, qr);
	else {
		qry(u << 1, l, mid, ql, mid);
		qry(u << 1 | 1, mid + 1, r, mid + 1, qr);
	}
}

void ssort(int l, int r, bool k) {
	if(l >= r) return ;
	for(int i = 0; i < 26; i ++) ans[i] = 0;
	qry(1, 1, n, l, r);
	if(k) {
		int la = l - 1;
		for(int i = 0; i < 26; i ++) if(ans[i]) {
			upd(1, 1, n, la + 1, la + ans[i], i);
			la += ans[i];
		}
	} else {
		int la = l - 1;
		for(int i = 25; i >= 0; i --) if(ans[i]) {
			upd(1, 1, n, la + 1, la + ans[i], i);
			la += ans[i];
		}
	}
}

void dfs(int u, int l, int r) {
	if(l == r) {
		for(int i = 0; i < 26; i ++) {
			if(sz[u][i]) {
				putchar(i + 'a'); break ;
			}
		}
		return ;
	}
	int mid = (l + r) >> 1; pd(u);
	dfs(u << 1, l, mid);
	dfs(u << 1 | 1, mid + 1, r);
}

int main() {
	scanf("%d%d", &n, &q);
	scanf("%s", s + 1);
	build(1, 1, n);
	for(int i = 1; i <= q; i ++) {
		int l, r, k;
		scanf("%d%d%d", &l, &r, &k);
		ssort(l, r, k);
//		dfs(1, 1, n); puts("");
	}
	dfs(1, 1, n);
	return 0;
}