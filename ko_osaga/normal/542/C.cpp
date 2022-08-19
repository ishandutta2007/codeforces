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

int a[205], n;
vector<int> gph[205];

lint gcd(lint x, lint y){
	return y ? gcd(y, x%y) : x;
}

lint lcm(lint x, lint y){
	return x * (y / gcd(x, y));
}

int indeg[205];

int dfs(int x){
	if(!indeg[x]) return 0;
	indeg[x] = 0;
	return 1 + dfs(a[x]);
}

int f(int x){
	int p = 0;
	for(auto &i : gph[x]){
		if(indeg[i]) continue;
		p = max(p, f(i) + 1);
	}
	return p;
}

int main(){
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> a[i];
		indeg[a[i]]++;
		gph[a[i]].push_back(i);
	}
	queue<int> que;
	for(int i=1; i<=n; i++){
		if(!indeg[i]){
			que.push(i);
		}
	}
	while(!que.empty()){
		int x = que.front();
		que.pop();
		indeg[a[x]]--;
		if(indeg[a[x]] == 0){
			que.push(a[x]);
		}
	}
	lint quot = 0, ret = 1;
	for(int i=1; i<=n; i++){
		if(indeg[i]) quot = max(quot, 1ll * f(i));
	}
	for(int i=1; i<=n; i++){
		if(indeg[i]){
			ret = lcm(ret, dfs(i));
		}
	}
	int coeff = 1;
	while(ret * coeff < quot) coeff++;
	cout << ret * coeff;
}