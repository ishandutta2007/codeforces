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
#include <bitset>
#include <iostream>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;
 
int n, a[1000005], b[1000005];
lint pa[1000005];
 
struct rmq{
	pi tree[2100000];
	int lim;
	void init(int n, int *a){
		for(lim = 1; lim <= n; lim <<= 1);
		fill(tree, tree+2100000, pi(2e9, 1e9));
		for(int i=1; i<=n; i++){
			tree[i+lim] = pi(a[i], i);
		}
		for(int i=lim; i; i--){
			tree[i] = min(tree[2*i], tree[2*i+1]);
		}
	}
	pi query(int s, int e){
		s += lim;
		e += lim;
		pi ret(2e9, 1e9);
		while(s < e){
			if(s%2 == 1) ret = min(ret, tree[s++]);
			if(e%2 == 0) ret = min(ret, tree[e--]);
			s >>= 1;
			e >>= 1;
		}
		if(s == e) ret = min(ret, tree[s]);
		return ret;
	}
}rmq;
 
lint dx[1000005];
 
void solve(int s, int e){
	if(s > e) return;
	pi t = rmq.query(s, e);
	solve(s, t.second - 1);
	solve(t.second + 1, e);
	int phase1 = min(e - t.second, t.second - s) + 1;
	int phase2 = max(e - t.second, t.second - s) + 1;
	dx[1] += t.first;
	dx[phase1+1] -= t.first;
	dx[phase2+1] -= t.first;
	dx[e-s+3] += t.first;
}
 
void get(lint *a, int *b){
	rmq.init(n, b);
	memset(dx, 0, sizeof(dx));
	solve(1, n);
	for(int i=1; i<=n; i++){
		dx[i] += dx[i-1];
	}
	for(int i=1; i<=n; i++){
		dx[i] += dx[i-1];
	}
	for(int i=1; i<=n; i++){
		a[i] = dx[i];
	}
}
 
int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
	}
	get(pa, a);
	int q;
	scanf("%d",&q);
	while(q--){
		int x; 
		scanf("%d",&x);
		printf("%.10f\n",1.0 * pa[x] / (n - x + 1));
	}
}