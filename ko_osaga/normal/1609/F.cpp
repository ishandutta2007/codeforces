#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using llf = long double;
using pi = pair<int, int>;
const int MAXT = 2100000;

int n;
vector<int> sl, sr, ul, ur;
pi merge(pi a, pi b){
	if(a > b) swap(a, b);
	if(a.first == b.first) a.second += b.second;
	return a;
}

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
	void init(int s = 1, int e = n, int p = 1){
		if(s == e){
			tree[p] = pi(0, 1);
			return;
		}
		int m = (s+e)/2;
		init(s, m, 2*p);
		init(m + 1, e, 2*p+1);
		tree[p] = merge(tree[2*p], tree[2*p+1]);
	}
	pi query(int s, int e, int ps = 1, int pe = n, int p = 1){
		if(e < ps || pe < s) return pi(1e9, 0);
		if(s <= ps && pe <= e) return tree[p];
		lazydown(p);
		int pm = (ps + pe) / 2;
		return merge(query(s, e, ps, pm, 2*p), query(s, e, pm+1, pe, 2*p+1));
	}
	void add(int s, int e, int x, int ps = 1, int pe = n, int p = 1){
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

void add(int s, int e, int x){
	seg.add(s+1, e+1, -x);
}

lint query(){
	if(seg.tree[1].first == -2) return seg.tree[1].second;
	return 0;
}

struct event{
	int pos, s, e, x;
	bool operator<(const event &p)const{
		return pos < p.pos;
	}
};

lint solve(vector<int> v){
	lint ret = 0;
	vector<event> swp;
	for(int i = 0; i < sz(v); i++){
		swp.push_back({sl[v[i]], v[i], sr[v[i]], +1});
		swp.push_back({v[i] + 1, v[i], sr[v[i]], -1});
	}
	for(int i = 0; i < sz(v); i++){
		swp.push_back({ul[v[i]], v[i], ur[v[i]], +1});
		swp.push_back({v[i] + 1, v[i], ur[v[i]], -1});
	}
	sort(all(swp));
	for(int i = 0; i < sz(swp); i++){
		add(swp[i].s, swp[i].e, swp[i].x);
		if(i < sz(swp) - 1) ret += 1ll * (swp[i + 1].pos - swp[i].pos) * query();
	}
	return ret;
}

static char buf[1 << 19]; // size : any number geq than 1024
static int idx = 0;
static int bytes = 0;
static inline int _read() {
	if (!bytes || idx == bytes) {
		bytes = (int)fread(buf, sizeof(buf[0]), sizeof(buf), stdin);
		idx = 0;
	}
	return buf[idx++];
}

static inline lint _readInt() {
	lint x = 0, s = 1;
	lint c = _read();
	while (c <= 32) c = _read();
	if (c == '-') s = -1, c = _read();
	while (c > 32) x = 10 * x + (c - '0'), c = _read();
	if (s < 0) x = -x;
	return x;
}


int main(){
	n = _readInt();
	vector<lint> a(n);
	vector<int> pcnt(n);
	sl.resize(n);
	sr.resize(n);
	ul.resize(n);
	ur.resize(n);
	seg.init();
	for(int i = 0; i < n; i++){
		a[i] = _readInt();
		pcnt[i] = __builtin_popcountll(a[i]);
	}
	{
		vector<int> stk;
		for(int i = 0; i < n; i++){
			while(sz(stk) && a[stk.back()] > a[i]) stk.pop_back();
			if(sz(stk)) sl[i] = stk.back() + 1;
			else sl[i] = 0;
			stk.push_back(i);
		}
	}
	{
		vector<int> stk;
		for(int i = 0; i < n; i++){
			while(sz(stk) && a[stk.back()] < a[i]) stk.pop_back();
			if(sz(stk)) ul[i] = stk.back() + 1;
			else ul[i] = 0;
			stk.push_back(i);
		}
	}
	{
		vector<int> stk;
		for(int i = n-1; i >=0; i--){
			while(sz(stk) && a[stk.back()] >= a[i]) stk.pop_back();
			if(sz(stk)) sr[i] = stk.back() - 1;
			else sr[i] = n-1;
			stk.push_back(i);
		}
	}
	{
		vector<int> stk;
		for(int i = n-1; i >=0; i--){
			while(sz(stk) && a[stk.back()] <= a[i]) stk.pop_back();
			if(sz(stk)) ur[i] = stk.back() - 1;
			else ur[i] = n-1;
			stk.push_back(i);
		}
	}
	vector<int> pcnts[70];
	for(int i = 0; i < n; i++){
		pcnts[pcnt[i]].push_back(i);
	}
	lint ret = 0;
	for(int i = 0; i < 69; i++){
		ret += solve(pcnts[i]);
	}
	cout << ret << endl;
}