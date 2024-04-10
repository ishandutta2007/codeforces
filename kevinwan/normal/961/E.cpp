#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mid ((l+r)>>1)
struct nd {
	nd *l, *r;
	ll v;
	nd() { l = r = NULL; }
};
ll num[200001];
nd *seg[200001];
void build(nd* x,int l, int r) {
	if (l == r)x->v=0;
	else build(x->l=new nd(), l, mid), build(x->r=new nd(), mid + 1, r), x->v = x->l->v + x->r->v;
}
void up(nd* n,nd* x, int a, ll b, int l, int r) {
	if (l == r)n->v = b+x->v;
	else if (a <= mid)up(n->l=new nd(), x->l, a, b, l, mid), n->r = x->r, n->v = n->l->v + n->r->v;
	else n->l = x->l, up(n->r=new nd(), x->r, a, b, mid + 1, r), n->v = n->l->v + n->r->v;
}
ll qu(nd* x, int a, int b, int l, int r) {
	if (a > b)return 0;
	if (l == a && r == b)return x->v;
	if (b <= mid)return qu(x->l, a, b, l, mid);
	if (a > mid)return qu(x->r, a, b, mid + 1, r);
	return qu(x->l, a, mid, l, mid) + qu(x->r, mid + 1, b, mid + 1, r);
}
int main() {
	int n, i;
	ll ans = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)scanf("%lld", num + i);
	for (i = 1; i <= n; i++)if (num[i] > n+1)num[i] = n+1;
	for (i = 0; i <= n; i++)seg[i] = new nd();
	build(seg[0],1, n+1);
	for (i = 1; i <= n; i++) {
		ans += qu(seg[min(i - 1, (int)num[i])], i, n+1, 1, n+1);
		up(seg[i], seg[i - 1],  num[i],1, 1, n+1);
	}
	printf("%lld", ans);
}