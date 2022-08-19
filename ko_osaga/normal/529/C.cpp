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

struct query{
	int sx, ex, sy, ey, idx;
}qr[200005];

struct rmq{
	int tree[270000], lim;
	void init(int n){
		for(lim = 1; lim <= n; lim <<= 1);
		memset(tree, 0x3f, sizeof(tree));
	}
	void add(int x, int v){
		x += lim;
		tree[x] = v;
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

int w, h, n, q;
pi a[200005];
int ret[200005];

void solve(){
	sort(a, a+n, [&](const pi &a, const pi &b){
		return a.second > b.second;
	});
	sort(qr, qr + q, [&](const query &a, const query &b){
		return a.sy > b.sy;
	});
	int p = 0;
	rmq.init(max(w, h));
	for(int i=0; i<q; i++){
		while(p < n && qr[i].sy <= a[p].second){
			rmq.add(a[p].first, a[p].second);
			p++;
		}
		if(rmq.query(qr[i].sx, qr[i].ex) <= qr[i].ey){
			ret[qr[i].idx] = 1;
		}
	}
}

int main(){
	cin >> w >> h >> n >> q;
	for(int i=0; i<n; i++){
		scanf("%d %d",&a[i].first, &a[i].second);
	}
	for(int i=0; i<q; i++){
		scanf("%d %d %d %d",&qr[i].sx, &qr[i].sy, &qr[i].ex, &qr[i].ey);
		qr[i].idx = i;
	}
	solve();
	for(int i=0; i<n; i++){
		swap(a[i].first, a[i].second);
	}
	for(int i=0; i<q; i++){
		swap(qr[i].sx, qr[i].sy);
		swap(qr[i].ex, qr[i].ey);
	}
	solve();
	for(int i=0; i<q; i++){
		puts(ret[i] ? "YES" : "NO");
	}
}