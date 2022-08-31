#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 50005;
const int MAXT = 132000;

pi merge(pi a, pi b){
	if(a < b) swap(a, b);
	if(a.first == b.first) a.second = min(a.second,b.second);
	return a;
}

int n;

struct seg{
	pi tree[MAXT];
	int lazy[MAXT];
	void lazydown(int p){
		for(int i=2*p; i<2*p+2; i++){
			tree[i].first += lazy[p];
			lazy[i] += lazy[p];
		}
		lazy[p] = 0;
	}
	void init(int s = 0, int e = n, int p = 1){
		lazy[p] = 0;
		if(s == e){
			tree[p] = pi(0, s);
			return;
		}
		int m = (s+e)/2;
		init(s, m, 2*p);
		init(m + 1, e, 2*p+1);
		tree[p] = merge(tree[2*p], tree[2*p+1]);
	}
	pi query(int s, int e, int ps = 0, int pe = n, int p = 1){
		if(e < ps || pe < s) return pi(-1e9, 0);
		if(s <= ps && pe <= e) return tree[p];
		lazydown(p);
		int pm = (ps + pe) / 2;
		return merge(query(s, e, ps, pm, 2*p), query(s, e, pm+1, pe, 2*p+1));
	}
	void add(int s, int e, int x, int ps = 0, int pe = n, int p = 1){
		if(e < ps || pe < s) return;
		if(s <= ps && pe <= e){
			tree[p].first += x;
			lazy[p] += x;
			return;
		}
		lazydown(p);
		int pm = (ps + pe) / 2;
		add(s, e, x, ps, pm, 2*p);
		add(s, e, x, pm+1, pe, 2*p+1);
		tree[p] = merge(tree[2*p], tree[2*p+1]);
	}
}seg;

pi a[MAXN];

auto cmp = [](int x, int y){
	return pi(a[x].second, a[x].first) > pi(a[y].second, a[y].first);
};

auto cmp2 = [](int x, int y){
	return a[x].first > a[y].first;
};

struct seg2{
	struct node{
		int idx, frm; 
		node operator+(const node &n)const{
			if(cmp(idx, n.idx)) return n;
			return *this;
		}
	}tree[MAXT];
	int lim;
	void init(int n){
		for(lim = 1; lim <= n; lim <<= 1);
		for(int i=0; i<lim; i++){
			tree[i + lim] = {n, i};
		}
		for(int i=lim-1; i; i--){
			tree[i] = tree[2*i] + tree[2*i+1];
		}
	}
	void update(int x, int v){
		x += lim;
		tree[x].idx = v;
		while(x > 1){
			x >>= 1;
			tree[x] = tree[2*x] + tree[2*x+1];
		}
	}
	pi query(int s, int e){
		node ret = (node){n, -1};
		s += lim;
		e += lim;
		while(s < e){
			if(s%2 == 1) ret = ret + tree[s++];
			if(e%2 == 0) ret = ret + tree[e--];
			s >>= 1;
			e >>= 1;
		}
		if(s == e) ret = ret + tree[s];
		return pi(ret.idx, ret.frm);
	}
}seg2;

int ans[MAXN];

bool trial(int k){
	vector<priority_queue<int, vector<int>, decltype(cmp)>> lvl(n, 
	priority_queue<int, vector<int>, decltype(cmp)>(cmp));
	priority_queue<int, vector<int>, decltype(cmp2)> pqForLast(cmp2);
	vector<int> f(n);
	for(int i=0; i<n; i++){
		f[i] = n - 1;
		lvl[n - 1].push(i);
		pqForLast.push(i);
	}
	seg.init();
	for(int i=0; i<n; i++){
		seg.add(i + 1, n, sz(lvl[i]) - 1);
	}
	seg2.init(n);
	auto update_node = [&](int x){
		seg2.update(x, sz(lvl[x]) ? lvl[x].top() : n);
	};
	update_node(n - 1);
	for(int i=0; i<n; i++){
		auto val = seg.query(i + 1, n);
		if(val.first > -i) return 0;
		int lastpos = val.second;
		int idx = -1;
		while(true){
			auto qq = seg2.query(i, lastpos - 1);
			if(f[qq.first] != qq.second){
				lvl[qq.second].pop();
				update_node(qq.second);
				continue;
			}
			idx = qq.first;
			break;
		}
		ans[i] = idx;
		lvl[f[idx]].pop();
		update_node(f[idx]);
		seg.add(f[idx] + 1, n, -1);
		f[idx] = -1;
		if(k + i < n - 1){
			while(sz(pqForLast) && a[pqForLast.top()].first <= a[idx].second){
				int x = pqForLast.top();
				pqForLast.pop();
				if(f[x] == -1) continue;
				f[x] = k + i;
				lvl[k + i].push(x);
				seg.add(k + i + 1, n - 1, 1);
				update_node(k + i);
			}
		}
	}
	return 1;
}

void solve(){
	scanf("%d",&n);
	for(int i=0; i<n; i++) scanf("%d %d",&a[i].first,&a[i].second);
	a[n] = pi(2e9, 2e9);
	int s = 1, e = n - 1;
	while(s != e){
		int m = (s+e)/2;
		if(trial(m)) e = m;
		else s = m + 1;
	}
	trial(s);
	for(int i=0; i<n; i++) printf("%d ", 1+ans[i]);
//	printf("%d\n", s);
//	for(int i=0; i<n; i++) printf("%d %d\n", a[ans[i]].first, a[ans[i]].second);
}

int main(){
//	int tc; scanf("%d",&tc);
int tc = 1;
	while(tc--){
		solve();
	}
}