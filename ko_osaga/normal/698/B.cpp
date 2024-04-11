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
typedef pair<int, int> pi;

vector<int> gph[200005];
int n, a[200005], ori[200005];

int deg[200005];
queue<int> que;


vector<int> v;
bool vis[200005];

void dfs(int x){
	if(vis[x]) return;
	vis[x] = 1;
	if(deg[x]) v.push_back(x);
	for(auto &i : gph[x]){
		dfs(i);
	}
}

void solve(int r){
	for(int i=1; i<=n; i++){
		gph[a[i]].push_back(i);
		gph[i].push_back(a[i]);
	}
	dfs(r);
	for(int i=1; i<=n; i++){
		if(vis[i] || !deg[i]) continue;
		v.clear();
		dfs(i);
		a[v[0]] = r;
	}
	int cnt = 0;
	for(int i=1; i<=n; i++){
		if(a[i] != ori[i]) cnt++;
	}
	printf("%d\n", cnt);
	for(int i=1; i<=n; i++){
		printf("%d ", a[i]);
	}

}

int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		ori[i] = a[i];
		deg[a[i]]++;
	}
	for(int i=1; i<=n; i++){
		if(deg[i] == 0){
			que.push(i);
		}
	}
	while(!que.empty()){
		int x = que.front();
		que.pop();
		deg[a[x]]--;
		if(deg[a[x]] == 0){
			que.push(a[x]);
		}
	}
	for(int i=1; i<=n; i++){
		if(a[i] == i){
			solve(i);
			return 0;
		}
	}
	for(int i=1; i<=n; i++){
		if(deg[i]){
			a[i] = i;
			solve(i);
			return 0;
		}
	}
}