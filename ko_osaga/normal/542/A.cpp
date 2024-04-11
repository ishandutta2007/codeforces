#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <functional>
#include <numeric>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <bitset>
#include <map>
#include <set>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

struct intv{
	int s, e, idx;
	bool operator<(const intv &b)const{
		return pi(s, -e) < pi(b.s, -b.e);
	}
}a[200005];

vector<intv> ok;
int n, m;

struct rmq{
	pi tree[530000];
	int lim;
	void init(vector<intv> &v){
		for(lim = 1; lim <= v.size(); lim <<= 1);
		for(int i=0; i<v.size(); i++){
			tree[i + lim] = pi(v[i].e - v[i].s, i);
		}
		for(int i=lim-1; i; i--){
			tree[i] = max(tree[2*i], tree[2*i+1]);
		}
	}
	pi query(int s, int e){
		pi ret(-1, -1);
		s += lim;
		e += lim;
		while(s < e){
			if(s%2 == 1) ret = max(ret, tree[s++]);
			if(e%2 == 0) ret = max(ret, tree[e--]);
			s >>= 1;
			e >>= 1;
		}
		if(s == e) ret = max(ret, tree[s]);
		return ret;
	}
}rmq;

lint ret;
int reti, retj;

void update(int s, int e, int x, int idx, intv node){
	lint gap = min(node.e, e) - max(node.s, s);
	if(gap <= 0) return;
	gap *= x;
	if(ret >= gap) return;
	ret = gap;
	retj = idx;
	reti = node.idx;
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=0; i<n; i++){
		scanf("%d %d",&a[i].s, &a[i].e);
		a[i].idx = i+1;
	}
	sort(a, a+n);
	int e = -2e9;
	for(int i=0; i<n; i++){
		if(a[i].e <= e) continue;
		e = a[i].e;
		ok.push_back(a[i]);
	}
	rmq.init(ok);
	for(int i=1; i<=m; i++){
		int s, e, x;
		scanf("%d %d %d",&s,&e,&x);
		int st = 0, ed = ok.size()-1;
		while(st != ed){
			int m = (st + ed) / 2;
			if(ok[m].s < s) st = m+1;
			else ed = m;
		}
		int st2 = 0, ed2 = ok.size()-1;
		while(st != ed){
			int m = (st + ed + 1) / 2;
			if(ok[m].e <= e) st2 = m;
			else ed2 = m-1;
		}
		if(st) update(s, e, x, i, ok[st-1]);
		if(ed + 1 < ok.size()) update(s, e, x, i, ok[ed+1]);
		if(st <= ed){
			int t = rmq.query(st, ed).second;
			update(s, e, x, i, ok[t]);
		}
	}
	if(ret == 0){
		puts("0");
		return 0;
	}
	printf("%lld\n%d %d",ret, reti, retj);
}