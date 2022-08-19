#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <functional>
#include <numeric>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <bitset>
#include <map>
#include <set>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

lint root(lint x){
	int s = 0, e = 100005;
	while(s != e){
		int m = (s+e+1)/2;
		if(1ll * m * m * m <= x) s = m;
		else e = m-1;
	}
	return 1ll * e;
}

map<lint, int> mp;

int f(lint x){
	if(x == 0) return 0;
	if(mp.find(x) != mp.end()) return mp[x];
	lint p = root(x);
	return mp[x] = max(f(x - p * p * p) + 1, f(p * p * p - 1));
}

lint tra(lint x){
	if(x == 0) return 0;
	lint p = root(x);
	if(mp[x - p * p * p] + 1 == mp[x]){
		return tra(x - p * p * p) + p * p * p;
	}
	return tra(p * p * p - 1);
}

int main(){
	lint x;
	cin >> x;
	printf("%d ",f(x));
	printf("%lld", tra(x));
}