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
typedef pair<lint, lint> pi;

int n;
int a[100005], s[100005];

struct cht{
	vector<pi> tree[270000];
	int lim;
	llf cross(pi a, pi b){
		return (llf) (b.second - a.second) / (a.first - b.first);
	}
	bool check(pi a, pi b, pi c){
		return (a.second - b.second) * (c.first - b.first) >
		(b.second - c.second) * (b.first - a.first);
	}
	void get_hull(vector<pi> &in, vector<pi> &out){
		for(auto &i : in){
			while(out.size() >= 2 && check(out[out.size()-2], out.back(), i)){
				out.pop_back();
			}
			out.push_back(i);
		}
	}
	lint tquery(vector<pi> &v, int x){
		auto func = [&](pi t, int x){
			return t.first * x + t.second;
		};
		int s = 0, e = v.size() - 1;
		while(s != e){
			int m = (s+e)/2;
			if(func(v[m], x) < func(v[m+1], x)){
				e = m;
			}
			else s = m+1;
		}
		return func(v[s], x);
	}
	void init(){
		for(lim = 1; lim <= n; lim <<= 1);
		for(int i=1; i<=n; i++){
			int p = i + lim;
			while(p >= 1){
				tree[p].push_back(pi(a[i], 1ll * a[i] * i - s[i]));
				p >>= 1;
			}
		}
		for(int i=1; i<=2*lim; i++){
			sort(tree[i].begin(), tree[i].end(), [&](const pi &a, const pi &b){
				if(a.first != b.first) return a.first > b.first;
				return a.second < b.second;
			});
			vector<pi> tmp;
			lint cpos = -111;
			for(auto &j : tree[i]){
				if(j.first == cpos) continue;
				cpos = j.first;
				tmp.push_back(j);
			}
			tree[i].clear();
			get_hull(tmp, tree[i]);
		}
	}
	lint query(int s, int e, int x){
		s += lim;
		e += lim;
		lint ret = 1e18;
		while(s < e){
			if(s%2 == 1) ret = min(ret, tquery(tree[s++], x));
			if(e%2 == 0) ret = min(ret, tquery(tree[e--], x));
			s >>= 1;
			e >>= 1;
		}
		if(s == e) ret = min(ret, tquery(tree[s], x));
		return ret;
	}
}seg;

int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		s[i] = a[i] + s[i-1];
	}
	seg.init();
	int q;
	scanf("%d",&q);
	while(q--){
		int x, y;
		scanf("%d %d",&x,&y);
		printf("%lld\n",seg.query(y-x+1, y, x-y) + s[y]);
	}
}