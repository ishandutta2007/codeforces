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

int a[2005][2005], n, comp[2005], p;
bool vis[2005];
vector<int> dfn;

void dfs(int x){
	vis[x] = 1;
	for(int i=1; i<=n; i++){
		if(!vis[i] && a[x][i]) dfs(i);
	}
	dfn.push_back(x);
}

void rdfs(int x, int p){
	comp[x] = p;
	for(int i=1; i<=n; i++){
		if(!comp[i] && a[i][x]) rdfs(i, p);
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=1; i<=n; i++){
		if(!vis[i]) dfs(i);
	}
	reverse(dfn.begin(), dfn.end());
	memset(vis, 0, sizeof(vis));
	for(auto &i : dfn){
		if(!comp[i]) rdfs(i, ++p);
	}
	puts(p == 1 ? "YES" : "NO");
}