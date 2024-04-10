#include <vector>
#include <algorithm>
#include <cstdio>
#include <cassert>
using namespace std;

typedef struct item * pitem;
struct item {
	int prior, value, cnt;
	long long sums[5];
	bool rev;
	pitem l, r;
};

int cnt (pitem it) {
	return it ? it->cnt : 0;
}

void upd_cnt (pitem it) {
	if (!it)
		return;
	it->cnt = cnt(it->l) + cnt(it->r) + 1;
	int off = cnt(it->l) % 5 - 4;
	for (int i = 0; i < 5; i++) {
		it->sums[i] = 0;
		if (it->l)
			it->sums[i] += it->l->sums[i];
		if (it->r)
			it->sums[i] += it->r->sums[(i - off) % 5];
	}
	it->sums[cnt(it->l) % 5] += it->value;
}

void push (pitem it) {
}

void merge (pitem & t, pitem l, pitem r) {
	push (l);
	push (r);
	if (!l || !r)
		t = l ? l : r;
	else if (l->prior > r->prior)
		merge (l->r, l->r, r),  t = l;
	else
		merge (r->l, l, r->l),  t = r;
	upd_cnt (t);
}

void split (pitem t, pitem & l, pitem & r, int key) {
	if (!t)
		return void( l = r = 0 );
	push (t);
	int cur_key = t->value;
	if (key <= cur_key)
		split (t->l, l, t->l, key),  r = t;
	else
		split (t->r, t->r, r, key),  l = t;
	upd_cnt (t);
}

int main(void) {
	pitem root = NULL;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char str[10];
		int x;
		scanf("%s", str);
		if (str[0] == 'a') {
			scanf("%d", &x);
			pitem l, r;
			split(root, l, r, x);
			pitem ni = new item;
			ni->cnt = 1;
			ni->l = ni->r = 0;
			ni->prior = rand();
			ni->value = x;
			for (int i = 0; i < 5; i++)
				ni->sums[i] = 0;
			ni->sums[0] = x;
			merge(l, l, ni);
			merge(root, l, r);
		} else if (str[0] == 'd') {
			scanf("%d", &x);
			pitem l, m, r;
			split(root, l, r, x);
			split(r, m, r, x + 1);
			assert(m && m->value == x && m->l == NULL && m->r == NULL);
			delete m;
			merge(root, l, r);
		} else if (str[0] == 's') {
			printf("%I64d\n", (root) ? root->sums[2] : 0);
		}
	}
	return 0;
}