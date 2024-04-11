#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int mod = 1e9 + 7;
const int MAXN = 1050005;

struct bit{
	int tree[MAXN];
	void add(int x, int v){
		for(int i=x; i<MAXN; i+=i&-i) tree[i] += v;
	}
	int kth(int v){
		int pos = 0;
		for(int i=19; i>=0; i--){
			if(pos + (1<<i) < MAXN && tree[pos + (1<<i)] < v){
				pos += (1<<i);
				v -= tree[pos];
			}
		}
		return pos + 1;
	}
	int query(int x){
		int ret = 0;
		for(int i=x; i; i-=i&-i) ret += tree[i];
		return ret;
	}
}bit;

int n, q, a[MAXN];

pi operator+(pi a, pi b){
	if(a > b) swap(a, b);
	if(a.first == b.first) a.second += b.second;
	return a;
}

struct seg{
	pi tree[MAXN];
	int lazy[MAXN];
	void lazydown(int p){
		for(int j=2*p; j<2*p+2; j++){
			tree[j].first += lazy[p];
			lazy[j] += lazy[p];
		}
		lazy[p] = 0;
	}
	void init(int s = 1, int e = n - 1, int p = 1){
		if(s == e){
			tree[p] = pi(0, 1);
			return;
		}
		int m = (s+e)/2;
		init(s, m, 2*p);
		init(m + 1, e, 2*p+1);
		tree[p] = tree[2*p] + tree[2*p+1];
	}
	void upd(int s, int e, int v, int ps = 1, int pe = n - 1, int p = 1){
		if(e < ps || pe < s) return;
		if(s <= ps && pe <= e){
			tree[p].first += v;
			lazy[p] += v;
			return;
		}
		int pm = (ps+pe)/2;
		lazydown(p);
		upd(s, e, v, ps, pm, 2*p);
		upd(s, e, v, pm+1, pe, 2*p+1);
		tree[p] = tree[2*p] + tree[2*p+1];
	}
}seg;

int rev[MAXN];

void upd(int p, int q, int v){
	if(p <= 0 || q > n) return;
	int l = rev[bit.kth(p)];
	int r = rev[bit.kth(q)];
	if(l < r) seg.upd(l, r - 1, v);
}

int query(){
	auto ans = seg.tree[1];
	if(ans.first == 0) return ans.second + 1;
	return 1;
}

int main(){
	scanf("%d %d",&n,&q);
	if(n == 1){
		while(q--) puts("1");
		return 0;
	}
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		bit.add(a[i], 1);
		rev[a[i]] = i;
	}
	seg.init();
	for(int i=1; i<n; i++) upd(i, i+1, +1);
	while(q--){
		int x, v; scanf("%d %d",&x,&v);
		int cur_idx = bit.query(a[x]);
		upd(cur_idx - 1, cur_idx, -1);
		upd(cur_idx, cur_idx + 1, -1);
		upd(cur_idx - 1, cur_idx + 1, +1);
		bit.add(a[x], -1);
		a[x] = v;
		rev[a[x]] = x;
		bit.add(a[x], +1);
		int nxt_idx = bit.query(a[x]);
		upd(nxt_idx - 1, nxt_idx + 1, -1);
		upd(nxt_idx - 1, nxt_idx, +1);
		upd(nxt_idx, nxt_idx + 1, +1);
		printf("%d\n", query());
	}
}