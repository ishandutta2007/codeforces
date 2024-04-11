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

vector<pi> gph[10005];
int n, m, op, cnt[10005];

int dep[10005], par[10005], vis[10005], pae[10005];
int survive[10005];

void dfs(int x, int p){
	vis[x] = 1;
	for(auto &i : gph[x]){
		if(!vis[i.first]){
			pae[i.first] = i.second;
			par[i.first] = x;
			dep[i.first] = dep[x] + 1;
			dfs(i.first, x);
		}
		else if(i.first != p && dep[i.first] < dep[x]){
			if(dep[i.first] % 2 == dep[x] % 2){
				cnt[i.second]++;
				for(int j=x; j!=i.first; j=par[j]){
					cnt[pae[j]]++;
				}
				op++;
			}
			else{
				cnt[i.second]--;
				for(int j=x; j!=i.first; j=par[j]){
					cnt[pae[j]]--;
				}
			}
		}
	}
}

int main(){
	cin >> n >> m;
	for(int i=1; i<=m; i++){
		int s, e;
		cin >> s >> e;
		gph[s].emplace_back(e, i);
		gph[e].emplace_back(s, i);
	}
	for(int i=1; i<=n; i++){
		if(!vis[i]) dfs(i, -1);
	}
	if(op == 0){
		printf("%d\n",m);
		for(int i=1; i<=m; i++){
			printf("%d ",i);
		}
		return 0;
	}
	vector<int> v;
	for(int i=1; i<=m; i++){
		if(!survive[i] && cnt[i] == op){
			v.push_back(i);
		}
	}
	printf("%d\n",v.size());
	for(auto &i : v) printf("%d ",i);
}