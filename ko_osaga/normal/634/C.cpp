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

struct seg{
	int tree[530000], lim;
	void init(int n){
		for(lim = 1; lim <= n; lim <<= 1);
	}
	void set(int x, int v){
		x += lim;
		tree[x] = v;
		while(x > 1){
			x >>= 1;
			tree[x] = tree[2*x] + tree[2*x+1];
		}
	}
	int sum(int s, int e){
		s += lim;
		e += lim;
		int ret = 0;
		while(s < e){
			if(s%2 == 1) ret += tree[s++];
			if(e%2 == 0) ret += tree[e--];
			s >>= 1; e >>= 1;
		}
		if(s == e) ret += tree[s];
		return ret;
	}
}seg1, seg2;

int n, k, a, b, q;

int main(){
	cin >> n >> k >> a >> b >> q;
	seg1.init(n);
	seg2.init(n);
	for(int i=0; i<q; i++){
		int t;
		scanf("%d",&t);
		if(t == 1){
			int d, t;
			scanf("%d %d",&d,&t);
			seg1.set(d, min(b, t + seg1.sum(d, d)));
			seg2.set(d, min(a, t + seg2.sum(d, d)));
		}
		else{
			int u;
			scanf("%d",&u);
			printf("%d\n",seg1.sum(1, u-1) + seg2.sum(u+k, n));
		}
	}
}