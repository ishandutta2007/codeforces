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
const int oo = 1e9;

int n, q;
int a[400005];

struct rmq{
	int tree[1050000], lim;
	void init(int n){
		memset(tree, 0, sizeof(tree));
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
		e+= lim;
		int ret = 0;
		while(s < e){
			if(s%2 == 1) ret = max(ret, tree[s++]);
			if(e%2 == 0) ret = max(ret, tree[e--]);
			s >>=1;
			e >>= 1;
		}
		if(s == e) ret= max(ret, tree[s]);
		return ret;
	}
}rmq;

int dpl[400005], dpr[400005], lis;
int cnt[400005];

bool check_indep(int x){
	return cnt[dpr[x]] != 1 || dpl[x] + dpr[x] != lis + 1;
}

int is_indep[400005];
int aux[400005], ret[400005];

struct query{
	int x, y, idx;
	bool operator<(const query &q)const{
		return x < q.x;
	}
};

int main(){
	scanf("%d %d",&n,&q);
	vector<int> v;
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		v.push_back(a[i]);
	}
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	for(int i=1; i<=n; i++){
		a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
	}
	rmq.init(n);
	for(int i=1; i<=n; i++){
		dpl[i] = rmq.query(1, a[i]-1) + 1;
		rmq.add(a[i], dpl[i]);
	}
	rmq.init(n);
	for(int i=n; i; i--){
		dpr[i] = rmq.query(a[i]+1, n) + 1;
		rmq.add(a[i], dpr[i]);
	}
	for(int i=1; i<=n; i++){
		lis = max(lis, dpl[i]);
	}
	for(int i=1; i<=n; i++){
		if(dpl[i] + dpr[i] == lis + 1){
			cnt[dpr[i]]++;
		}
	}
	for(int i=1; i<=n; i++){
		is_indep[i] = check_indep(i);
	}
	vector<query> qr;
	for(int i=0; i<q; i++){
		int x, y;
		scanf("%d %d",&x, &y);
		if(is_indep[x]){
			ret[i] = lis;
		}
		else ret[i] = lis - 1;
		qr.push_back({x, y, i});
	}
	sort(qr.begin(), qr.end());
	rmq.init(n);
	int pnt = 1;
	for(int i=0; i<q; i++){
		while(pnt <= n && pnt < qr[i].x){
			rmq.add(a[pnt], dpl[pnt]);
			pnt++;
		}
		int sy = lower_bound(v.begin(), v.end(), qr[i].y) - v.begin();
		aux[qr[i].idx] += rmq.query(1, sy);
	}
	pnt = n;
	rmq.init(n);
	for(int i=q-1; i>=0; i--){
		while(pnt && pnt > qr[i].x){
			rmq.add(a[pnt], dpr[pnt]);
			pnt--;
		}
		int ey = upper_bound(v.begin(), v.end(), qr[i].y) - v.begin() + 1;
		aux[qr[i].idx] += rmq.query(ey, n);
	}
	for(int i=0; i<q; i++){
		ret[i] = max(ret[i], aux[i] + 1);
		printf("%d\n",ret[i]);
	}
}