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

// a[i] < a[j], i > j   
// -> permutation graph
// independent set -> LIS

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
			s >>= 1; e >>= 1;
		}
		if(s == e) ret = max(ret, tree[s]);
		return ret;
	}
}rmq;

int n, a[100005];

int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%d",&a[i]);
	}
	rmq.init(n);
	int ret = 0;
	for(int i=0; i<n; i++){
		int dp = rmq.query(0, a[i] - 1) + 1;
		rmq.add(a[i], dp);
		ret = max(ret, dp);
	}
	cout << ret;
}