#include <bits/stdc++.h>

#define dbg(x) //cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define DMAX 100100
#define NMAX 
#define MMAX 

using namespace std;


int n, k, x, a[DMAX], pre[DMAX], m, nxt[DMAX], t, y;
string s;
set<int> pos[DMAX];


template<class T>
ostream& operator<<(ostream& out, vector<T> v)
{
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

struct tr{
	int k, p, v;
	long long s;
	tr * l, * r;
	tr(int _k, int _v) { s = v = _v; k = _k; p = rand(); r = l = NULL;}
	// tr() { p = rand();}
};

void upd(tr * t) {
	if(!t) return;
	t->s = 1LL * t->v;
	if(t->l) t->s += t->l->s;
	if(t->r) t->s += t->r->s;
}

void split(tr * rt, int key, tr * &l, tr * &r) {
	if(rt == NULL) l = r = NULL;
	else if(key < rt->k) split(rt->l, key, l, rt->l), r = rt;
	else split(rt->r, key, rt->r, r), l = rt;
	upd(rt);
}

void merge(tr * &rt, tr * l, tr * r) {
	if(!l || !r) rt = l ? l : r;
	else if(l->p > r->p) merge(l->r, l->r, r), rt = l;
	else merge(r->l, l, r->l), rt = r;
	upd(rt);
} 

void insert(tr * &rt, int key, int val){
	tr * e, *l, *r;
	split(rt, key, l, r);
	split(l, key - 1, l, e);
	if(e == NULL) e = new tr(key, val);
	else e->v += val;
	upd(e);
	merge(l, l, e);
	merge(rt, l, r);
}

// void insert (tr * &rt, pitem it, int key, int val) {
// 	if (!rt)
// 		rt = new tr(key, val);
// 	else if (it->p > t->p)
// 		split (t, it->key, it->l, it->r),  t = it;
// 	else
// 		insert (it->key < t->key ? t->l : t->r, it);
// }

void remove(tr * &rt, int key, int val) {
	tr * e, *l, *r;
	split(rt, key, l, r);
	split(l, key - 1, l, e);
	if(e != NULL) e->v -= val;
	upd(e);
	if(!e || e->v > 0) merge(l, l, e);
	merge(rt, l, r);
}


tr * st[4 * DMAX];

void build(int node, int l, int r) {
	if(l == r) {
		if(pre[l])
			st[node] = new tr(pre[l], l - pre[l]);
		else st[node] = NULL;
		return;
	}
	int mid = (l + r) / 2;
	build(2 * node, l, mid);
	build(2 * node + 1, mid + 1, r);
	st[node] = NULL;
	for(int i = l; i <= r; i++)
		if(pre[i])
			insert(st[node], pre[i], i - pre[i]);
}

void update(int node, int l, int r, int pos, int oldpre) {
	if(l == r) {
		st[node] = new tr(pre[pos], pos - pre[pos]);
		return;
	}
	int mid = (l + r) / 2;
	if(pos <= mid) update(2 * node, l, mid, pos, oldpre);
	else update(2 * node + 1, mid + 1, r, pos, oldpre);
	remove(st[node], oldpre, pos - oldpre);
	insert(st[node], pre[pos], pos - pre[pos]);
}

long long query(int node, int l, int r, int x, int y) {
	if(y < l || x > r) return 0;
	if(x <= l && r <= y) {
		tr * l, * r;
		split(st[node], x - 1, l, r);
		long long ans = r ? r->s : 0;
		merge(st[node], l, r);
		return ans;
	}
	int mid = (l + r) / 2;
	long long ans = 0LL;
	if(x <= mid) ans += query(2 * node, l, mid, x, y);
	if(y > mid) ans += query(2 * node + 1, mid + 1, r, x, y);
	return ans;
}

int getPre(int i) {
	auto it = pos[a[i]].lower_bound(i);
		if(it != pos[a[i]].begin()) {
			it--;
			return *it;
		}
		return 0;
}

int getNxt(int i) {
	auto it = pos[a[i]].upper_bound(i);
	if(it != pos[a[i]].end())
		return *it;
	return 0;
}

int main()
{
	srand(time(0));
	ios_base::sync_with_stdio(false);
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) {
	scanf("%d ", &a[i]);
		pos[a[i]].insert(i);
		pre[i] = getPre(i);
		if(pre[i]) nxt[pre[i]] = i;
	}

	build(1, 1, n);
	for(int i = 1; i <= m; i++) {
		scanf("%d %d %d", &t, &x, &y);
		if(t == 1) {

			int p = x, opn;
			int prei = pre[p], nxti = nxt[p], k = y;
			if(a[p] == y) continue;

			pos[a[p]].erase(p); pos[k].insert(p); a[p] = k;
			pre[nxti] = prei; nxt[prei] = nxti;
			
			pre[p] = getPre(p); if(pre[p]) nxt[pre[p]] = p;
			nxt[p] = getNxt(p); if(nxt[p]) opn = pre[nxt[p]], pre[nxt[p]] = p;
//			pre[0] = nxt[0] = 0;
			
			update(1, 1, n, p, prei);
			if(nxti) update(1, 1, n, nxti, p);
			if(nxt[p]) update(1, 1, n, nxt[p], opn);
		}
		else printf("%lld\n", query(1, 1, n, x, y)); //cout << query(1, 1, n, x, y) << '\n';
	}
	// dbg(query(1, 1, n, 1, 5));
	return 0;
}