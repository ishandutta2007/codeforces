#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
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

int n, sz[200005], d1[200005], d2[200005];

vector<int> gph[200005];

void dfs(int x, int p, int d){
	if(x != 1 && gph[x].size() == 1){
		sz[x] = d1[x] = d2[x] = 1;
		return;
	}
	int minv = 1e9, sum = 0;
	for(auto &i : gph[x]){
		if(i == p) continue;
		dfs(i, x, d+1);
		sz[x] += sz[i];
		minv = min(minv, d2[i]);
		sum += sz[i] - d1[i] + 1;
	}
	d1[x] = sz[x] - minv + 1;
	d2[x] = sum;
}

int main(){
	scanf("%d",&n);
	if(n == 1){
		puts("1 1");
		return 0;
	}
	for(int i=0; i<n-1; i++){
		int s, e;
		scanf("%d %d",&s,&e);
		gph[s].push_back(e);
		gph[e].push_back(s);
	}
	dfs(1, 0, 0);
	printf("%d %d",d1[1], d2[1]);
}