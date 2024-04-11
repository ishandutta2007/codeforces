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
	int tree[1050000], lim;
	void init(int n){
		for(lim = 1; lim <= n; lim <<= 1);
	}
	void update(int x, int v){
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
			s >>= 1;
			e >>= 1;
		}
		if(s == e) ret = max(ret, tree[s]);
		return ret;
	}
}rmq;

int n, a[500005];
vector<int> comp;

int bef[500005], nxt[500005], lst[500005];
int dp[500005], track[500005];
vector<int> occur[500005];

int ok(int s, int e){
	if(e - s + 1 < 4) return 0;
	auto st = lower_bound(occur[a[e]].begin(), occur[a[e]].end(), s);
	auto ed = upper_bound(occur[a[e]].begin(), occur[a[e]].end(), e);
	if(ed - st >= 4) return 2;
	return s <= bef[e] - 1 && rmq.query(s, bef[e] - 1) > bef[e];
}

int main(){
	scanf("%d",&n);
	comp.push_back(0);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		comp.push_back(a[i]);
	}
	sort(comp.begin(), comp.end());
	comp.resize(unique(comp.begin(), comp.end()) - comp.begin());
	memset(nxt, 0x3f, sizeof(nxt));
	rmq.init(n);
	for(int i=1; i<=n; i++){
		a[i] = lower_bound(comp.begin(), comp.end(), a[i]) - comp.begin();
		occur[a[i]].push_back(i);
		bef[i] = lst[a[i]];
		nxt[bef[i]] = i;
		lst[a[i]] = i;
	}
	int e = 1;
	for(int i=1; i<=n; i++){
		dp[i] = dp[i-1];
		track[i] = i;
		while(e < i && ok(e+1, i)) e++;
		if(ok(e, i)){
			if(dp[i] < dp[e-1] + 1){
				dp[i] = dp[e-1] + 1;
				track[i] = e-1;
			}
		}
		if(bef[i]) rmq.update(bef[i], i);
	}
	int p = max_element(dp, dp + n + 1) - dp;
	printf("%d\n", 4 * dp[p]);
	vector<int> v;
	while(dp[p]){
		while(dp[p] == dp[p-1]) p--;
		int u = track[p];
		if(ok(u+1, p) == 2){
			auto ed = upper_bound(occur[a[p]].begin(), occur[a[p]].end(), p);
			for(int j=0; j<4; j++){
				ed--;
				v.push_back(*ed);
			}
			p = u;
			continue;
		}
		v.push_back(p);
		v.push_back(nxt[u+1]);
		v.push_back(bef[p]);
		v.push_back(u+1);
		p = u;
	}
	reverse(v.begin(), v.end());
	for(auto &i : v){
		printf("%d ",comp[a[i]]);
	}
}