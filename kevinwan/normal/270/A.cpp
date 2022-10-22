#include <bits/stdc++.h>
using namespace std;
/*struct nd {
	nd *l, *r,*p;
	int val, pri;
	nd(int v) {
		val = v;
		pri = rand();
	}
};
nd* treap;
nd* find(int num,nd* cur=treap) {
	while (cur != NULL) {
		if (num > cur->val)cur = cur->r;
		else if (num < cur->val)cur = cur->l;
		else return cur;
	}
	return NULL;
}
nd* insert(int num, nd* cur = treap) {
	nd* par = NULL;
	while (cur != NULL) {
		if (num > cur->val) { par = cur;  cur=cur->r; }
		else if (num < cur->val) { par = cur; cur = cur->l; }
		else if (num == cur->val)return cur;
	}
}*/
bitset<181> screw;
int main() {
	int kkk;
	scanf("%d", &kkk);
	for (int i = 1; i <= 120; i++)if (360 % i == 0)screw[180 - i] = 1;
	while (kkk--) {
		int you;
		scanf("%d", &you);
		if (screw[you])printf("YES\n");
		else printf("NO\n");
	}
}