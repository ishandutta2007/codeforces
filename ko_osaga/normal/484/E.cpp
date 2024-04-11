#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
#include <utility>
#include <bitset>
#include <iostream>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

int n;
pi a[100005];

struct inner{
	int l, r, opt, sz;
};

inner merge(inner a, inner b){
	inner ret;
	ret.sz = a.sz + b.sz;
	ret.opt = max(a.opt, b.opt);
	ret.opt = max(ret.opt, a.r + b.l);
	ret.l = a.l, ret.r = b.r;
	if(a.sz == a.l) ret.l = a.l + b.l;
	if(b.sz == b.r) ret.r = b.r + a.r;
	return ret;
}

struct seg{
	inner tree[270000];
	void init(int s, int e, int p){
		if(s == e){
			tree[p] = {0, 0, 0, 1};
			return;
		}
		int m = (s+e)/2;
		init(s, m, 2*p);
		init(m+1, e, 2*p+1);
		tree[p] = merge(tree[2*p], tree[2*p+1]);
	}
	void add(int pos, int s, int e, int p){
		if(s == e){
			tree[p] = {1, 1, 1, 1};
			return;
		}
		int m = (s+e)/2;
		if(pos <= m) add(pos, s, m, 2*p);
		else add(pos, m+1, e, 2*p+1);
		tree[p] = merge(tree[2*p], tree[2*p+1]);
	}
	inner query(int s, int e, int ps, int pe, int p){
		if(e < ps || pe < s) return (inner){0, 0, 0, 0};
		if(s <= ps && pe <= e) return tree[p];
		int pm = (ps + pe) / 2;
		return merge(query(s, e, ps, pm, 2*p), query(s, e, pm+1, pe, 2*p+1));
	}
}seg;

int l[100005], r[100005], w[100005];
int st[100005], ed[100005], mi[100005], ans[100005];
int proc[100005];

int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i].first);
		a[i].second = i;
	}
	sort(a+1, a+n+1);
	reverse(a+1, a+n+1);
	int q;
	scanf("%d",&q);
	for(int i=0; i<q; i++){
		scanf("%d %d %d",&l[i], &r[i], &w[i]);
		st[i] = 1, ed[i] = n;
	}
	while(1){
		int ok = 0;
		for(int i=0; i<q; i++){
			proc[i] = i;
			if(st[i] != ed[i]) ok = 1;
			mi[i] = (st[i] + ed[i]) / 2;
		}
		if(!ok) break;
		seg.init(1, n, 1);
		sort(proc, proc + q, [&](const int &a, const int &b){
			return mi[a] < mi[b];
		});
		int pnt = 0;
		for(int i=1; i<=n; i++){
			seg.add(a[i].second, 1, n, 1);
			while(pnt < q && mi[proc[pnt]] == i){
				ans[proc[pnt]] = seg.query(l[proc[pnt]], r[proc[pnt]], 1, n, 1).opt;
				pnt++;
			}
		}
		for(int i=0; i<q; i++){
			if(ans[i] >= w[i]) ed[i] = mi[i];
			else st[i] = mi[i] + 1;
		}
	}
	for(int i=0; i<q; i++){
		printf("%d\n",a[st[i]].first);
	}
}