#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int N = 223456;

struct tnode {
	tnode *l, *r;
} tpool[N * 50], * tcur = tpool;

struct node {
	node *go[27], *p;
	tnode *r;
	int val;
	vector<node*> son;
} pool[N], *cur = pool, *rt;
char s[N], t[N];
int n, m, l, r, q, ch[N], w[N];

node *append(node *p, int w) {
	node *np = cur++;
	np->val = p->val + 1;
	for (; p && !p->go[w]; p = p->p)
		p->go[w] = np;
	if (!p) np->p = rt;
	else {
		node *q = p->go[w];
		if (q->val == p->val + 1) np->p = q;
		else {
			node *nq = cur++;
			nq->val = p->val + 1;
			memcpy(nq->go, q->go, sizeof(q->go));
			nq->p = q->p;
			np->p = q->p = nq;
			for (; p && p->go[w] == q; p = p->p)
				p->go[w] = nq;
		}
	}
	return np;
}

tnode *build(int l, int r, int x) {
	tnode *p = tcur++;
	if (l != r) {
		int mid = (l + r) >> 1;
		if (x <= mid) p->l = build(l, mid, x);
		else p->r = build(mid + 1, r, x);
	}
	return p;
}
tnode* merge(tnode *a, tnode *b) {
	tnode *p = tcur++;
	if (!a || !b) {
		if (a) p = a; else p = b;
	} else {
		p->l = merge(a->l, b->l);
		p->r = merge(a->r, b->r);
	}
	return p;
}
bool exists(tnode *a, int l, int r, int L, int R) {
	if (!a) return 0;
	if (L == l && R == r) return 1;
	int mid = (l + r) >> 1;
	if (R <= mid) return exists(a->l, l, mid, L, R);
	else if (L > mid) return exists(a->r, mid + 1, r, L, R);
	else return exists(a->l, l, mid, L, mid) || exists(a->r, mid + 1, r, mid + 1, R);
}

void dfs(node *p) {
	for (auto q : p->son) {
		dfs(q);
		p->r = merge(p->r, q->r);
	}
}

void init() {
	rt = cur++;
	node *np = rt;
	for (int i = 1; i <= n; i++) {
		np = append(np, s[i] - 'a');
		np->r = build(1, n, i);
	}
	for (node *p = pool; p != cur; p++)
		if (p->p) p->p->son.push_back(p);
	dfs(rt);
}

bool valid(int d, node *p) {
	if (p && l + d - 1 <= r) return exists(p->r, 1, n, l + d - 1, r);
	return 0;
}

bool dfs(int dep, int ty, node *p) {
	if (ty == 1) {
		for (int j = 0; j < dep; j++) {
			putchar(ch[j] + 'a');
		}
		puts("");
		return 1;
	}
	for (int c = ty ? 0 : max(w[dep], 0); c < 26; c++) {
		if (valid(dep + 1, p->go[c])) {
			ch[dep] = c;
			if (dfs(dep + 1, ty | (c > w[dep]), p->go[c])) {
				return 1;
			}
		}
	}
	return 0;
}

void debug(tnode *p, int l, int r) {
	if (!p) return;
	if (l == r) {
		printf("%d ", l);
		return;
	}
	int mid = (l + r) >> 1;
	debug(p->l, l, mid);
	debug(p->r, mid + 1, r);
}

int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	init();
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		scanf("%d%d%s", &l, &r, t);
		m = strlen(t);
		for (int j = 0; j < m; j++) w[j] = t[j] - 'a';
		w[m] = -1;
		if (!dfs(0, 0, rt)) {
			puts("-1");
		}
	}
}