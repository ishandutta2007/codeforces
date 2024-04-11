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

int n, a[1005];
map<int, int> mp;
set<pi> vis;

int solve(int x, int y){
	if(vis.find(pi(x, y)) != vis.end()) return 0;
	vis.insert(pi(x, y));
	stack<int> stk;
	stk.push(x);
	stk.push(y);
	int ret = 2;
	mp[x]--; mp[y]--;
	while(1){
		tie(x, y) = pi(y, x-y);
		if(mp.find(y) != mp.end() && mp[y] > 0){
			stk.push(y);
			mp[y]--;
			ret++;
		}
		else break;
	}
	while(!stk.empty()){
		mp[stk.top()]++;
		stk.pop();
	}
	return ret;
}

int main(){
	cin >> n;
	for(int i=0; i<n; i++) cin >> a[i], mp[a[i]]++;
	int ret = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(i != j){
				ret = max(ret, solve(a[i], a[j]));
			}
		}
	}
	cout << ret;
}