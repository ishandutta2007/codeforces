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
typedef pair<int, int> pi;

vector<int> graph[100005];

int n, dep[100005];

void dfs(int x, int p){
	for(auto &i : graph[x]){
		if(i == p) continue;
		dep[i] = dep[x] + 1;
		dfs(i, x);
	}
}

int main(){
	cin >> n;
	for(int i=0; i<n-1; i++){
		int s, e;
		scanf("%d %d",&s,&e);
		graph[s].push_back(e);
		graph[e].push_back(s);
	}
	dep[1] = 1;
	dfs(1, 0);
	double ret = 0;
	for(int i=1; i<=n; i++){
		ret += 1.0 / dep[i];
	}
	printf("%.10f",ret);
}