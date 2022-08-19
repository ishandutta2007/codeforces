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

struct bit{
	int tree[100005], lim;
	void init(int n){
		memset(tree, 0, sizeof(tree));
		lim = n;
	}
	void add(int x, int v){
		while(x <= lim){
			tree[x] += v;
			x += x & -x;
		}
	}
	int f(int x){
		int r = 0;
		while(x){
			r += tree[x];
			x -= x & -x;
		}
		return r;
	}
	int query(int s, int e){
		return f(e) - f(s-1);
	}
}bit, rbit;

vector<int> v;
int n, a[100005];
lint k, invl[100005], invr[100005];

int main(){
	scanf("%d %lld",&n,&k);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		v.push_back(a[i]);
	}
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	for(int i=1; i<=n; i++){
		a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
	}
	bit.init(v.size());
	for(int i=1; i<=n; i++){
		invl[i] = bit.query(a[i] + 1, v.size()) + invl[i-1];
		bit.add(a[i], 1);
	}
	bit.init(v.size());
	for(int i=n; i; i--){
		invr[i] = bit.query(1, a[i] - 1) + invr[i+1];
		bit.add(a[i], 1);
	}
	// [1] [2 1 7]
	// [1] [1 7]
	// [1] [7]
	// [1 3] [1 7]
	// [1 3] [7]
	// [1 3 2] [7]
	// [1 3 2 1] []
	int e = 1;
	bit.init(v.size());
	bit.add(a[1], 1); 
	rbit.init(v.size());
	for(int i=1; i<=n; i++){
		rbit.add(a[i], 1);
	}
	lint cur = rbit.query(1, a[1] - 1);
	lint ret = 0;
	for(int i=2; i<=n; i++){
		// [1, i] / [e, n]
		while((e < i) || (e <= n && cur + invl[i-1] + invr[e] > k)){
			cur -= bit.query(a[e] + 1, v.size());
			rbit.add(a[e], -1);
			e++;
		}
		ret += n + 1 - e;
		bit.add(a[i], 1);
		cur += rbit.query(1, a[i] - 1);
	}
	cout << ret;
}