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
typedef pair<lint, lint> pi;

int n, a[200005];
lint s[200005];

struct cht{
	pi hull[200005];
	int p, sz;
	void init(){
		p = sz = 0;
	}
	bool ok(pi a, pi b, pi c){
		return 1ll * (a.second - b.second) * (c.first - b.first) > 1ll * (b.first - a.first) * (b.second - c.second);
	}
	void add(lint a, lint b){
		while(sz - 2 >= p && ok(hull[sz-2], hull[sz-1], pi(a, b))){
			sz--;
		}
		hull[sz++] = pi(a, b);
	}
	lint query(int x){
		if(p == sz) return -1e18;
		auto func = [&](pi p, int x){
			return p.first * x + p.second;
		};
		while(p+1 < sz && func(hull[p], x) < func(hull[p+1], x)) p++;
		return func(hull[p], x);
	}
}cht;

int main(){
	scanf("%d",&n);
	lint base = 0;
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		base += 1ll * i * a[i];
	}
	cht.init();
	for(int i=1; i<=n; i++){
		s[i] = s[i-1] + a[i];
	}
	int pmax = -1e9;
	lint ret = 0;
	for(int i=1; i<=n; i++){
		ret = max(ret, cht.query(i) - s[i]);
		if(a[i] > pmax){
			pmax = a[i];
			cht.add(a[i], s[i] - 1ll * i * a[i]);
		}
	}
	cht.init();
	pmax = 1e9;
	for(int i=n; i; i--){
		ret = max(ret, cht.query(-i) - s[i-1]);
		if(a[i] < pmax){
			pmax = a[i];
			cht.add(-a[i], s[i-1] - 1ll * i * a[i]);
		}
	}
	printf("%lld",base + ret);
}