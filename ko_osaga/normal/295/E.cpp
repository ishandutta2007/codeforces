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
const int mod = 1e9 + 7;

struct node{
	lint inside, sum, size;
};

node add(node l, node r){
	return {l.inside + r.inside - l.sum * r.size + r.sum * l.size, l.sum + r.sum, l.size + r.size};
}

struct seg{
	node tree[530000];
	void add(int pos, int real, int s, int e, int p, int v){
		if(s == e){
			if(v == -1) tree[p] = {0, 0, 0};
			else tree[p] = {0, real, 1};
			return;
		}
		int m = (s+e)/2;
		if(pos <= m) add(pos, real, s, m, 2*p, v);
		else add(pos, real, m+1, e, 2*p+1, v);
		tree[p] = ::add(tree[2*p], tree[2*p+1]);
	}
	node query(int s, int e, int ps, int pe, int p){
		if(e < ps || pe < s) return {0, 0, 0};
		if(s <= ps && pe <= e) return tree[p];
		int pm = (ps + pe) / 2;
		return ::add(query(s, e, ps, pm, 2*p), query(s, e, pm+1, pe, 2*p+1));
	}
}seg;

int n, q, a[100005], b[100005];
int t[100005], l[100005], r[100005];

vector<int> v;

int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		v.push_back(a[i]);
		b[i] = a[i];
	}
	scanf("%d",&q);
	for(int i=0; i<q; i++){
		scanf("%d %d %d",&t[i],&l[i],&r[i]);
		if(t[i] == 1){
			b[l[i]] += r[i];
			v.push_back(b[l[i]]);
		}
	}
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	int sz = v.size();
	for(int i=1; i<=n; i++){
		int lbnd = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
		seg.add(lbnd, a[i], 0, sz-1, 1, 1);
	}
	for(int i=0; i<q; i++){
		if(t[i] == 1){
			int lbnd = lower_bound(v.begin(), v.end(), a[l[i]]) - v.begin();
			seg.add(lbnd, a[l[i]], 0, sz-1, 1, -1);
			a[l[i]] += r[i];
			lbnd = lower_bound(v.begin(), v.end(), a[l[i]]) - v.begin();
			seg.add(lbnd, a[l[i]], 0, sz-1, 1, 1);
		}
		else{
			int lbnd = lower_bound(v.begin(), v.end(), l[i]) - v.begin();
			int ubnd = upper_bound(v.begin(), v.end(), r[i]) - v.begin()-1;
			printf("%lld\n",seg.query(lbnd, ubnd, 0, sz-1, 1).inside);
		}
	}
}