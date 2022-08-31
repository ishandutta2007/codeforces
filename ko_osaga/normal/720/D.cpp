#include<bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using lint = long long;
const int MAXN = 1000005;
const int MAXT = 2100000;
const int mod = 1e9 + 7;

struct seg{
	int tree[MAXT];
	int lazy[MAXT];
	void lazydown(int p){
		if(lazy[p]){
			lazy[2*p] = lazy[2*p+1] = 1;
			tree[2*p] = tree[2*p+1] = 0;
			lazy[p] = 0;
		}
	}
	void add(int pos, int s, int e, int p, int v){
		if(s == e){
			tree[p] += v;
			tree[p] %= mod;
			return;
		}
		lazydown(p);
		int m = (s+e)/2;
		if(pos <= m) add(pos, s, m, 2*p, v);
		else add(pos, m+1, e, 2*p+1, v);
		tree[p] = (tree[2*p] + tree[2*p+1]) % mod;
	}
	void zero(int s, int e, int ps, int pe, int p){
		if(e < ps || pe < s) return;
		if(s <= ps && pe <= e){
			tree[p] = 0;
			lazy[p] = 1;
			return;
		}
		int pm = (ps+pe)/2;
		lazydown(p);
		zero(s, e, ps, pm, 2*p);
		zero(s, e, pm+1, pe, 2*p+1);
		tree[p] = (tree[2*p] + tree[2*p+1]) % mod;
	}
	int sum(int s, int e, int ps, int pe, int p){
		if(e < ps || pe < s) return 0;
		if(s <= ps && pe <= e) return tree[p];
		int pm = (ps+pe)/2;
		lazydown(p);
		return (sum(s, e, ps, pm, 2*p) + sum(s, e, pm+1, pe, 2*p+1)) % mod;
	}
}seg;

int n, w, h;
vector<pi> add[MAXN], rem[MAXN];
int dp[MAXN];

void upd(int x, int v){
	seg.add(x, 1, h, 1, v);
}

void zero(int s, int e){
	seg.zero(s, e, 1, h, 1);
}

int sum(int s, int e){
	return seg.sum(s, e, 1, h, 1);
}

int main(){
	scanf("%d %d %d",&w,&h,&n);
	for(int i=0; i<n; i++){
		int sx, sy, ex, ey;
		scanf("%d %d %d %d",&sx,&sy,&ex,&ey);
		add[sx].push_back(pi(sy, ey));
		rem[ex + 1].push_back(pi(sy, ey));
	}
	upd(1, 1);
	set<pi> s;
	for(auto &i : add[1]) s.insert(i);
	for(int i=2; i<=w; i++){
		vector<pi> v;
		for(auto &j : add[i]){
			if(j.second == h) continue;
			int pos = j.second + 1;
			auto l = s.upper_bound(pi(pos, 1e9));
			int stp = 1;
			if(l != s.begin()) stp = prev(l)->second + 1;
			if(stp < pos) v.push_back(pi(pos, sum(stp, pos - 1)));
		}
		for(auto &j : add[i]){
			zero(j.first, j.second);
		}
		for(auto &j : rem[i]) s.erase(j);
		for(auto &j : add[i]) s.insert(j);
		for(auto &j : v){
			if(j.first > h) continue;
			auto l = s.upper_bound(pi(j.first, 1e9));
			if(l != s.begin() && prev(l)->second >= j.first){
				continue;
			}
			upd(j.first, j.second);
		}
	}
	auto l = (s.size() ? (s.rbegin()->second) : 0) + 1;
	cout << sum(l, h) << endl;
}