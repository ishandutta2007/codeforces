#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
const int mod = 998244353;
const int MOD = 998244353;
const int MAXT = 555555;
using lint = long long;
using ll = long long;
using pi = pair<int, int>;

int n, q;
int N;

struct seg{
	int tree[MAXT], lazy1[MAXT], lazy2[MAXT];
	void init(){
		fill(lazy2, lazy2 + MAXT, 1);
	}
	void lazydown(int ps, int pe, int p){
		int pm = (ps+pe)/2;
		tree[2*p] = 1ll * tree[2*p] * lazy2[p] % mod;
		tree[2*p+1] = 1ll * tree[2*p+1] * lazy2[p] % mod;
		lazy2[2*p] = 1ll * lazy2[2*p] * lazy2[p] % mod;
		lazy2[2*p+1] = 1ll * lazy2[2*p+1] * lazy2[p] % mod;
		lazy1[2*p] = 1ll * lazy1[2*p] * lazy2[p] % mod;
		lazy1[2*p+1] = 1ll * lazy1[2*p+1] * lazy2[p] % mod;
		lazy2[p] = 1;
		tree[2*p] += 1ll * lazy1[p] * (pm - ps + 1) % mod;
		tree[2*p+1] += 1ll * lazy1[p] * (pe - pm) % mod;
		lazy1[2*p] += lazy1[p];
		lazy1[2*p+1] += lazy1[p];
		tree[2*p] %= mod;
		tree[2*p+1] %= mod;
		lazy1[2*p] %= mod;
		lazy1[2*p+1] %= mod;
		lazy1[p] = 0;
	}

	void add(int s, int e, int ps, int pe, int p, int v){
		if(e < ps || pe < s) return;
		if(s <= ps && pe <= e){
			tree[p] += v * (pe - ps + 1);
			lazy1[p] += v;
			tree[p] %= mod; lazy1[p] %= mod;
			return;
		}
		int pm = (ps+pe)/2;
		lazydown(ps, pe, p);
		add(s, e, ps, pm, 2*p, v);
		add(s, e, pm+1, pe, 2*p+1, v);
		tree[p] = (tree[2*p] + tree[2*p+1]) % mod;
	}
	void mult(int s, int e, int ps, int pe,int p, int v){	
		if(e < ps || pe < s) return;
		if(s <= ps && pe <= e){
			tree[p] *= v;
			lazy1[p] *= v;
			lazy2[p] *= v;
			tree[p] %= mod; lazy1[p] %= mod;
			lazy2[p] %= mod;
			return;
		}
		int pm = (ps+pe)/2;
		lazydown(ps, pe, p);
		mult(s, e, ps, pm, 2*p, v);
		mult(s, e, pm+1, pe, 2*p+1, v);
		tree[p] = (tree[2*p] + tree[2*p+1]) % mod;
	}
	int query(int s, int e, int ps, int pe, int p){
		if(e < ps || pe < s) return 0;
		if(s <= ps && pe <= e) return tree[p];
		int pm = (ps+pe)/2;
		lazydown(ps, pe, p);
		return (query(s, e, ps, pm, 2*p) + query(s, e, pm+1, pe, 2*p+1)) % mod;
	}
}seg;


void incr(int l, int r){
	seg.add(l, r, 1, n, 1, 1);
}

void mult(int l, int r){
	seg.mult(l, r, 1, n, 1, 2);
}

int getsum(int l, int r){
	return seg.query(l, r, 1, n, 1);
}

set<pi> s[MAXN];

pi sex(pi l, pi r){
	return pi(max(l.first, r.first), min(l.second, r.second));
}

int main(){
	scanf("%d %d",&n,&q);
	seg.init();
	while(q--){
		int t;
		scanf("%d",&t);
		if(t == 1){
			int l, r, x;
			scanf("%d %d %d",&l,&r,&x);
			vector<pi> upd;
			while(true){
				auto it = s[x].lower_bound(pi(l, -1));
				if(it != s[x].begin()) it = prev(it);
				while(it != s[x].end() && it->second <= l-1) it = next(it);
				if(it == s[x].end() || it->first > r) break;
				pi insec = sex(*it, pi(l, r));
				assert(insec.first <= insec.second);
				upd.push_back(insec);
				pi rem = *it;
				s[x].erase(it);
				pi v = sex(rem, pi(1, l-1));
				if(v.first <= v.second) s[x].insert(v);
				v = sex(rem, pi(r+1, n));
				if(v.first <= v.second) s[x].insert(v);
			}
			sort(upd.begin(), upd.end());
			int lst = l;
			for(auto &i : upd){
				if(lst < i.first){
					incr(lst, i.first - 1);
				}
				mult(i.first, i.second);
				lst = i.second + 1;
			}
			if(lst <= r) incr(lst, r);
			s[x].insert(pi(l, r));
		}
		else{
			int l, r;
			scanf("%d %d",&l,&r);
			printf("%d\n", getsum(l, r));
		}
	}
}