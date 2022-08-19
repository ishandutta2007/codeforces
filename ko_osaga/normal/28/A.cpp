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

int n, m, x[505], y[505], l[505];
int ret[505];

bool solve(){
	x[n] = x[0];
	y[n] = y[0];
	set<pi> s;
	for(int i=0; i<m; i++){
		s.insert(pi(l[i], i));
	}
	for(int i=0; i<n; i+=2){
		int dist = abs(x[i+1] - x[i]) + abs(y[i+1] - y[i]) + abs(x[i+2] - x[i+1]) + abs(y[i+2] - y[i+1]);
		auto t = s.lower_bound(pi(dist, -1e8));
		if(t != s.end() && t->first == dist){
			ret[i] = -1;
			ret[i+1] = t->second+1;
			s.erase(t);
		}
		else return 0;
	}
	return 1;
}

int main(){
	cin >> n >> m;
	for(int i=0; i<n; i++){
		cin >> x[i] >> y[i];
	}
	for(int i=0; i<m; i++){
		cin >> l[i];
	}
	if(solve()){
		puts("YES");
		for(int i=0; i<n; i++){
			printf("%d ",ret[i]);
		}
		return 0;
	}
	rotate(x, x+1, x+n);
	rotate(y, y+1, y+n);
	if(solve()){
		puts("YES");
		rotate(ret, ret+n-1, ret+n);
		for(int i=0; i<n; i++){
			printf("%d ",ret[i]);
		}
		return 0;
	}
	puts("NO");
}