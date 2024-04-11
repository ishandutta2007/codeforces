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

int n;
pi a[200005];

struct rmq{
	int tree[530000], lim;
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
			s/=2;
			e/=2;
		}
		if(s == e) ret = max(ret, tree[s++]);
		return ret;
	}
}rmq;

int maxr[200005];
int nxt[200005][18], nxtl[200005][18];

int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		int x, y;
		scanf("%d %d",&x,&y);
		a[i] = pi(x, x+y);
	}
	rmq.init(n);
	for(int i=n-1; i>=0; i--){
		int lw = lower_bound(a, a+n, pi(a[i].second+1, -1e9)) - a;
		maxr[i] = max(a[i].second, rmq.query(i+1, lw-1));
		rmq.add(i, maxr[i]);
	}
	nxt[n][0] = n;
	for(int i=0; i<n; i++){
		nxt[i][0] = lower_bound(a, a+n, pi(maxr[i]+1, -1e9)) - a;
		if(nxt[i][0] != n){
			nxtl[i][0] = a[nxt[i][0]].first - maxr[i];
		}
	}
	for(int i=1; i<18; i++){
		for(int j=0; j<=n; j++){
			nxt[j][i] = nxt[nxt[j][i-1]][i-1];
			nxtl[j][i] = nxtl[j][i-1] + nxtl[nxt[j][i-1]][i-1];
		}
	}
	int q;
	scanf("%d",&q);
	while(q--){
		int s, e;
		scanf("%d %d",&s, &e);
		s--, e--;
		int ret = 0;
		for(int i=17; i>=0; i--){
			if(nxt[s][i] < e){
				ret += nxtl[s][i];
				s = nxt[s][i];
			}
		}
		if(maxr[s] < a[e].first){
			ret += nxtl[s][0];
		}
		printf("%d\n", ret);
	}
}