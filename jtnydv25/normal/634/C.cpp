#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define sd(x) scanf("%d", &(x))
// N is max insert operations. Memory: 4*N
const int N = 5e6+10;
//key acc to heap, value acc to BT, 0 represents NULLPO 
int lft[N], rgt[N], value[N], cnt = 0, size[N];
unsigned key[N]; ll sum[N];
static unsigned generate_key() {
	static unsigned x = 123456789, y = 362436069, z = 521288629, w = 88675123;
	unsigned t = x ^ x<<11;
	x = y; y = z; z = w;
	return w = w ^ w>>19 ^ t ^ t>>8;
}
inline void fix(int x){ size[x] = (value[x] == 0) ? size[rgt[x]] : size[lft[x]] + size[rgt[x]] + 1;
 sum[x] = sum[lft[x]] + sum[rgt[x]] + value[x];}
struct treap{
	int root;
	treap(){root = 0;}
	int merge(int L, int R){
		if(L == 0){ fix(R); return R;}
		if(R == 0){ return L;}
		if(key[L] > key[R]){ rgt[L] = merge(rgt[L], R), fix(L); }
		else{ lft[R] = merge(L, lft[R]); fix(R);}
		return (key[L] > key[R]) ? L : R;
	}
	pii split(int T, int X){
		if(T == 0) return mp(0,0);
		if(value[T] <= X){
			pii P = split(rgt[T], X);
			rgt[T] = P.F; fix(T);
			return mp(T, P.S);
		}
		pii P = split(lft[T], X);
		lft[T] = P.S; fix(T);
		return mp(P.F, T);
	}
	int find(int rt, int X){
		if(rt == 0 || value[rt] == X) return rt;
		if(value[rt] < X) return find(rgt[rt], X);
		return find(lft[rt], X);
	}
	int find(int X){ return find(root, X);}
	void insert(int X){
		key[++cnt] = generate_key(); value[cnt] = sum[cnt] = X; size[cnt] = (X > 0);
		pii P = split(root, X);
		int L = merge(P.F, cnt);
		root = merge(L, P.S);
	}
	// remember to change data for all ancestors.
	void erase(int rt, int up, int x){
		if(rt == 0) return;
		sum[rt] -= x;
		if(x) size[rt] --;
		if(value[rt] == x){
			if(up == 0) root = merge(lft[rt], rgt[rt]);
			else if(lft[up] == rt) lft[up] = merge(lft[rt], rgt[rt]);
			else rgt[up] = merge(lft[rt], rgt[rt]);
			return;	
		}
		if(value[rt] > x) erase(lft[rt], rt, x);
		else erase(rgt[rt], rt, x);
	}
	void erase(int x){ if(!find(x)) return; erase(root, 0, x);}
	// get sum of all <= x
	ll getsum(int rt, int x){
		if(rt == 0) return 0;
		if(value[rt] <= x) return value[rt] + sum[lft[rt]] + getsum(rgt[rt], x);
		return getsum(lft[rt], x);
	}
	ll getsum(int x){ return getsum(root, x);}
	int getcount(int rt, int x){
		if(rt == 0) return 0;
		if(value[rt] <= x) return 1 + size[lft[rt]] + getcount(rgt[rt], x);
		return getcount(lft[rt], x);
	}
	int getcount(int x){ return getcount(root, x);}
};

const int M = 4e5 + 10;
treap T[(M << 1) + 10];
int A[M], n;
void update(int i, int v, int v_new, int s = 1, int e = n, int ind = 1){
	if(s > i || e < i) return;
	T[ind].erase(v); T[ind].insert(v_new);
	int mid = (s + e) >> 1;
	if(s == e) return;
	update(i, v, v_new, s, mid, ind << 1);
	update(i, v, v_new, mid + 1, e, (ind << 1) | 1);
}
// get sum of all elements <= x in range [l, r]
ll get_sum(int l, int r, int x, int s = 1, int e = n, int ind = 1){
	if(s > r || l > e)return 0;
	if(s >= l && e <= r) return T[ind].getsum(x);
	int mid = (s + e) >> 1;
	return get_sum(l, r, x, s, mid, ind << 1) + get_sum(l, r, x, mid + 1, e, (ind << 1) | 1);
}
int get_count(int l, int r, int x, int s = 1, int e = n, int ind = 1){
	if(s > r || l > e) return 0;
	if(s >= l && e <= r) return T[ind].getcount(x);
	int mid = (s + e) >> 1;
	return get_count(l, r, x, s, mid, ind << 1) + get_count(l, r, x, mid + 1, e, (ind << 1) | 1);
}
void Insert(int i, int x, int s = 1, int e = n, int ind = 1){
	if(s > i || e < i) return;
	T[ind].insert(x);
	if(s == e) return;
	int mid = (s + e) >> 1;
	Insert(i, x, s, mid, ind << 1);
	Insert(i, x, mid + 1, e, (ind << 1) | 1);
}
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define T int
#define ordered_set tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>
ordered_set zeroes;
int main(){
	int k, a, b, q, type, d, p, x;
	sd(n), sd(k), sd(a), sd(b), sd(q);
	for(int i = 1; i <= n; i++) zeroes.insert(i);
	while(q--){
		sd(type);
		if(type == 1){
			sd(d), sd(x);
			if(!A[d]) Insert(d, x), zeroes.erase(d);
			else update(d, A[d], A[d] + x);
			A[d] += x;
			continue;
		}
		sd(p);
		ll sumlessthanb = get_sum(1, p - 1, b);
		int countgtb = p - 1 - get_count(1, p - 1, b) - zeroes.order_of_key(p);
		ll sumlessthana = get_sum(p + k, n, a);
		int countgta = n - (p + k - 1) - get_count(p + k, n, a) - (zeroes.size() - zeroes.order_of_key(p + k));
		ll answer = sumlessthanb + sumlessthana + b * 1ll * countgtb + a * 1ll *countgta;
		printf("%lld\n", answer);
	}
}