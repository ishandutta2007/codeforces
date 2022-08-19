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

struct rmq{
	int tree[270000], lim;
	void init(int n){
		for(lim = 1; lim <= n; lim <<= 1);
		memset(tree,0x3f,sizeof(tree));
	}
	void upd(int x, int v){
		x += lim;
		tree[x] = v;
		while(x > 1){
			x >>= 1;
			tree[x] = min(tree[2*x], tree[2*x+1]);
		}
	}
	int q(int s, int e){
		s += lim;
		e += lim;
		int ret = 1e9;
		while(s < e){
			if(s%2 == 1) ret = min(ret, tree[s++]);
			if(e%2 == 0) ret = min(ret, tree[e--]);
			s >>= 1;
			e >>= 1;
		}
		if(s == e) ret = min(ret, tree[s]);
		return ret;
	}
}rmq1, rmq2;

int n, a[100005];

int main(){
	scanf("%d",&n);
	rmq1.init(n);
	rmq2.init(n);
	for(int i=1; i<=n; i++){
		scanf("%d",a+i);
		rmq1.upd(i, a[i]); // minimum
		rmq2.upd(i, -a[i]); // maximum
	}
	int e = 1, ret = 0;
	for(int i=1; i<=n; i++){
		while(e+1 <= n && -rmq2.q(i, e+1) - rmq1.q(i, e+1) <= 1){
			e++;
		}
		ret = max(ret, e - i + 1);
	}
	cout << ret;
}