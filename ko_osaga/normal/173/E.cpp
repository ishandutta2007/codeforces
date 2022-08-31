#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <limits.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <numeric>
#include <deque>
#include <bitset>
#include <iostream>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
const int oo = 2e9;

struct t1{
	int first, second, idx;
	bool operator<(const t1 &b)const{
		return first < b.first;
	}
}a[100005];

struct seg{
	int s, e, x, cnt, idx;
}b[100005];

struct t2{
	int st, ed, c, idx;
}c[100005];

int loc[100005];
int n, k;
vector<int> comp;

struct bit{
	int tree[100005];
	void init(){
		memset(tree, 0, sizeof(tree));
	}
	void add(int x, int v){
		x += 2;
		while(x <= n+2){
			tree[x] += v;
			x += x & -x;
		}
	}
	int query(int x){
		x += 2;
		int ret = 0;
		while(x){
			ret += tree[x];
			x -= x & -x;
		}
		return ret;
	}
}bit;

struct rmq{
	int tree[270000], lim;
	void init(int n){
		for(lim = 1; lim <= n; lim <<= 1);
	}
	void add(int x, int v){
		x += lim;
		tree[x] = max(tree[x], v);
		while(x > 1){
			x >>= 1;
			tree[x] = max(tree[2*x], tree[2*x+1]);
		}
	}
	int query(int s, int e){
		s += lim;
		e += lim;
		int ret = 0;
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

int ret[100005];

int main(){
	scanf("%d %d",&n,&k);
	for(int i=0; i<n; i++){
		scanf("%d",&a[i].second);
		comp.push_back(a[i].second);
	}
	sort(comp.begin(), comp.end());
	comp.resize(unique(comp.begin(), comp.end()) - comp.begin());
	for(int i=0; i<n; i++){
		a[i].second = lower_bound(comp.begin(), comp.end(), a[i].second) - comp.begin();
	}
	for(int i=0; i<n; i++){
		scanf("%d",&a[i].first);
		a[i].idx = i+1;
	}
	sort(a, a+n);
	for(int i=0; i<n; i++){
		b[i].s = lower_bound(a, a+n, (t1){a[i].first - k, 0, 0}) - a;
		b[i].e = upper_bound(a, a+n, (t1){a[i].first + k, 0, 0}) - a - 1;
		b[i].x = a[i].second;
		loc[a[i].idx] = i;
	}
	sort(b, b+n, [&](const seg &a, const seg &b){
		return pi(a.s, a.e) < pi(b.s, b.e);
	});
	int pnt = 0;
	for(int i=0; i<n; i++){
		while(pnt <= b[i].e){
			bit.add(a[pnt++].second, 1);
		}
		b[i].cnt += bit.query(b[i].x);
	}
	pnt = 0;
	bit.init();
	for(int i=0; i<n; i++){
		while(pnt < b[i].s){
			bit.add(a[pnt++].second, 1);
		}
		b[i].cnt -= bit.query(b[i].x);
	}
	int q;
	scanf("%d",&q);
	for(int i=0; i<q; i++){
		int x, y;
		scanf("%d %d",&x, &y);
		x = loc[x], y = loc[y];
		if(x > y) swap(x, y);
		int ed = lower_bound(b, b+n, (seg){x+1, 0, 0, 0}, [&](const seg &a, const seg &b){
			return a.s < b.s;
		}) - b - 1;
		int st = lower_bound(b, b+n, (seg){0, y, 0, 0}, [&](const seg &a, const seg &b){
			return a.e < b.e;
		}) - b;
		c[i] = {st, ed, max(a[x].second, a[y].second), i};
	}
	for(int i=0; i<n; i++) b[i].idx = i;
	rmq.init(n);
	sort(b, b+n, [&](const seg &a, const seg &b){
		return a.x < b.x;
	});
	sort(c, c+q, [&](const t2 &a, const t2 &b){
		return a.c > b.c;
	});
	int p = n-1;
	for(int i=0; i<q; i++){
		while(p >= 0 && b[p].x >= c[i].c){
			rmq.add(b[p].idx, b[p].cnt);
			p--;
		}
		ret[c[i].idx] = rmq.query(c[i].st, c[i].ed);
	}
	for(int i=0; i<q; i++){
		if(ret[i] <= 1) ret[i] = -1;
		printf("%d\n", ret[i]);
	}
}