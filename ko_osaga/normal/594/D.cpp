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

lint ipow(int x, int p){
	lint ret = 1, piv = x;
	while(p){
		if(p&1) ret *= piv;
		piv *= piv;
		ret %= mod;
		piv %= mod;
		p >>= 1;
	}
	return ret;
}

struct seg{
	lint tree[530000], lim;
	void init(int n){
		for(lim = 1; lim <= n; lim <<= 1);
		fill(tree, tree + 530000, 1);
	}
	void add(int x, int v){
		x += lim;
		tree[x] *= v;
		tree[x] %= mod;
		while(x > 1){
			x >>= 1;
			tree[x] = 1ll * tree[2*x] * tree[2*x+1] % mod;
		}
	}
	int query(int s, int e){
		s += lim;
		e += lim;
		lint ret = 1;
		while(s < e){
			if(s%2 == 1) ret = (ret * tree[s++]) % mod;
			if(e%2 == 0) ret = (ret * tree[e--]) % mod;
			s >>= 1;
			e >>= 1;
		}
		if(s == e) ret *= tree[s];
		return ret % mod;
	}
}seg1, seg2;

int low[1000005], inv[1000005], sis[1000005];
int n, q, a[200005];

struct elem{
	int pos, nxt, val;
};

struct qry{
	int s, e, idx;
}qr[200005];

struct your_problem_is_boring{
	int s, e, idx, sgn, retp;
};

vector<elem> v;
lint ret[200005];

int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
	}
	for(int i=2; i<=1000000; i++){
		for(int j=i; j<=1000000; j+=i){
			if(!low[j]) low[j] = i;
		}
	}
	seg1.init(n);
	seg2.init(n);
	for(int i=1; i<=n; i++){
		seg1.add(i, a[i]);
		int p = a[i];
		set<int> s;
		while(p > 1){
			s.insert(low[p]);
			p /= low[p];
		}
		for(auto &j : s){
			v.push_back({i, sis[j], (int)(1ll * (j - 1) * ipow(j, mod - 2) % mod)});
			sis[j] = i;
		}
	}
	scanf("%d",&q);
	vector<your_problem_is_boring> v2;
	for(int i=0; i<q; i++){
		scanf("%d %d",&qr[i].s, &qr[i].e);
		ret[i] = seg1.query(qr[i].s, qr[i].e);
		qr[i].idx = i;
		v2.push_back({0, qr[i].s - 1, qr[i].s-1, -1, i});
		v2.push_back({0, qr[i].s-1, qr[i].e, 1, i});
	}
	sort(v2.begin(), v2.end(), [&](const your_problem_is_boring &a, const your_problem_is_boring &b){
		return a.idx < b.idx;
	});
	int p1 = 0, p2 = 0;
	for(int i=0; i<=n; i++){
		while(p1 < v.size() && v[p1].pos == i){
			seg2.add(v[p1].nxt, v[p1].val);
			p1++;
		}
		while(p2 < v2.size() && v2[p2].idx == i){
			if(v2[p2].sgn == -1){
				ret[v2[p2].retp] *= ipow(seg2.query(v2[p2].s, v2[p2].e), mod - 2);
			}
			else{
				ret[v2[p2].retp] *= seg2.query(v2[p2].s, v2[p2].e);
			}
			ret[v2[p2].retp] %= mod;
			p2++;
		}
	}
	for(int i=0; i<q; i++){
		printf("%lld\n",ret[i]);
	}
}