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

vector<int> vx, vy;
int n, par[100005];
pi a[100005], b[100005];
map<pi, int> mp;

struct seg{
	multiset<pi> base[280000];
	pi tree[270000];
	int lim;
	void init(int n){
		for(lim = 1; lim <= n; lim <<= 1);
		fill(tree, tree + 270000, pi(1e9, 1e9));
	}
	void add(int x, int y, int p){
		x += lim;
		base[x].insert(pi(y, p));
		tree[x] = *base[x].begin();
		while(x > 1){
			x >>= 1;
			tree[x] = min(tree[2*x], tree[2*x+1]);
		}
	}
	void del(int x, int y, int p){
		x += lim;
		base[x].erase(base[x].find(pi(y, p)));
		if(base[x].empty()) tree[x] = pi(1e9, 1e9);
		else tree[x] = *base[x].begin();
		while(x > 1){
			x >>= 1;
			tree[x] = min(tree[2*x], tree[2*x+1]);
		}
	}
	pi query(int s, int e){
		s += lim;
		e += lim;
		pi ret(1e9, 1e9);
		while(s < e){
			if(s%2 == 1) ret = min(ret, tree[s++]);
			if(e%2 == 0) ret = min(ret, tree[e--]);
			s >>= 1;
			e >>= 1;
		}
		if(s == e) ret = min(ret, tree[s]);
		return ret;
	}
}seg;

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		scanf("%d %d %d %d",&a[i].first,&a[i].second,&b[i].first,&b[i].second);
		vx.push_back(a[i].first);
		vy.push_back(a[i].second);
	}
	vx.push_back(0);
	vy.push_back(0);
	sort(vx.begin(), vx.end());
	sort(vy.begin(), vy.end());
	seg.init(vx.size());
	for(int i=0; i<n; i++){
		a[i].first = lower_bound(vx.begin(), vx.end(), a[i].first) - vx.begin();
		a[i].second = lower_bound(vy.begin(), vy.end(), a[i].second) - vy.begin();
		seg.add(a[i].first, a[i].second, i);
	}
	queue<pi> que;
	queue<int> idx;
	que.push(pi(0, 0));
	idx.push(-2);
	memset(par, -1, sizeof(par));
	while(!que.empty()){
		auto f = que.front();
		auto d = idx.front();
		que.pop(); idx.pop();
		int p = upper_bound(vx.begin(), vx.end(), f.first) - vx.begin();
		while(1){
			auto v = seg.query(0, p-1).second;
			if(v < n && vy[a[v].second] <= f.second){
				par[v] = d;
				que.push(b[v]);
				idx.push(v);
				seg.del(a[v].first, a[v].second, v);
			}
			else break;
		}
	}
	if(par[n-1] != -1){
		stack<int> stk;
		for(int j=n-1; j != -2; j=par[j]){
			stk.push(j);
		}
		printf("%d\n",stk.size());
		while(!stk.empty()) printf("%d ",stk.top() + 1), stk.pop();
		return 0;
	}
	puts("-1");
}