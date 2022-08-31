#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 500005;
const int MAXT = 1050000;

int n;
int pos[MAXN], nxt[MAXN];
int arr[MAXN], a[MAXN];

pi merge(pi a, pi b){
	if(a > b) swap(a, b);
	if(a.first == b.first) a.second += b.second;
	return a;
}

struct seg{
	int lazy[MAXT];
	pi tree[MAXT];
	void init(int s, int e, int p){
		if(s == e){
			tree[p] = pi(0, 1);
			return;
		}
		int m = (s+e)/2;
		init(s, m, 2*p);
		init(m+1, e, 2*p+1);
		tree[p] = merge(tree[2*p], tree[2*p+1]);
	}
	void lazydown(int p){
		lazy[2*p] += lazy[p];
		lazy[2*p+1] += lazy[p];
		tree[2*p].first += lazy[p];
		tree[2*p+1].first += lazy[p];
		lazy[p] = 0;
	}
	void add(int s, int e, int ps, int pe, int p, int v){
		if(e < ps || pe < s) return;
		if(s <= ps && pe <= e){
			tree[p].first += v;
			lazy[p] += v;
			return;
		}
		int pm = (ps+pe)/2;
		lazydown(p);
		add(s, e, ps, pm, 2*p, v);
		add(s, e, pm+1, pe, 2*p+1, v);
		tree[p] = merge(tree[2*p], tree[2*p+1]);
	}
	pi query(int s, int e, int ps, int pe, int p){
		if(e < ps || pe < s) return pi(1e9, 0);
		if(s <= ps && pe <= e) return tree[p];
		int pm = (ps + pe) / 2;
		lazydown(p);
		return merge(query(s, e, ps, pm, 2*p), query(s, e, pm+1, pe, 2*p+1));
	}
}seg;

void upd(int s, int e, int x){
	seg.add(s, e, 1, n, 1, x);
}

pi query(int s, int e){
	return seg.query(s, e, 1, n, 1);
}

int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		if(pos[a[i]]) nxt[i] = pos[a[i]];
		pos[a[i]] = i;
	}
	seg.init(1, n, 1);
	for(int i=1; i<=n; i++) nxt[i] = max(nxt[i-1], nxt[i]);
	vector<int> stk;
	a[0] = 1e9;
	stk.push_back(0);
	lint ret = 0;
	for(int i=1; i<=n; i++){
		while(!stk.empty() && a[stk.back()] <= a[i]){
			int prv = stk.back();
			stk.pop_back();
			upd(stk.back() + 1, prv, a[i] - a[prv]);
		}
		upd(i, i, a[i]);
		stk.push_back(i);
		upd(nxt[i] + 1, i, -1);
		auto v = query(nxt[i] + 1, i);
		if(v.first == 0) ret += v.second;
	}
	cout << ret << endl;
}