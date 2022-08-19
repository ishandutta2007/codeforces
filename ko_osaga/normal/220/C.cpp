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

int pos1[100005], pos2[100005], n;

struct rmq{
	int tree[270000], lim;
	void init(int n){
		memset(tree, 0x3f, sizeof(tree));
		for(lim = 1; lim <= n; lim <<= 1);
	}
	void add(int s, int e, int x){
		s += lim;
		e += lim;
		while(s < e){
			if(s%2 == 1) tree[s] = min(tree[s], x);
			if(e%2 == 0) tree[e] = min(tree[e], x);
			s = (s+1)/2;
			e = (e-1)/2;
		}
		if(s == e) tree[s] = min(tree[s], x);
	}
	int query(int x){
		x += lim;
		int ret = 1e9;
		while(x){
			ret = min(ret, tree[x]);
			x >>= 1;
		}
		return ret;
	}
}rmq1, rmq2;

int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		int t;
		scanf("%d",&t);
		pos1[t] = i-1;
	}
	for(int i=1; i<=n; i++){
		int t;
		scanf("%d",&t);
		pos2[t] = i-1;
	}
	rmq1.init(n);
	rmq2.init(n);
	for(int i=1; i<=n; i++){
		rmq2.add(0, pos2[i] - pos1[i], pos2[i] - pos1[i]);
		rmq2.add(pos2[i] + 1, min(pos2[i] - pos1[i] + n, n-1), pos2[i] - pos1[i] + n);
		rmq1.add(max(pos2[i] - pos1[i] + 1, 0), pos2[i], pos1[i] - pos2[i]);
		rmq1.add(min(pos2[i] - pos1[i] + n + 1, n), n-1, pos1[i] - pos2[i] - n);
	}
	for(int i=0; i<n; i++){
		printf("%d\n",min(i + rmq1.query(i), rmq2.query(i) - i));
	}
}