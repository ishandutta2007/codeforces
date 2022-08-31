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

int n, m;
vector<int> gph[100005];

bool vis[100005];
int cnt;

void dfs(int x){
	if(vis[x]) return;
	vis[x] = 1;
	cnt -= 2;
	for(auto &i : gph[x]){
		cnt++;
		dfs(i);
	}
}
int main(){
	cin >> n >> m;
	for(int i=0; i<m; i++){
		int s, e;
		cin >> s >> e;
		gph[s].push_back(e);
		gph[e].push_back(s);
	}
	int ret = 0;
	for(int i=1; i<=n; i++){
		if(!vis[i]){
			cnt = 0;
			dfs(i);
			if(cnt == -2) ret++;
		}
	}
	cout << ret;
}