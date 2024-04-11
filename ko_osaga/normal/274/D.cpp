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

vector<int> gph[200005], rev[200005];
int p, n, m, piv;
pi a[100005];

vector<int> dfn;
bool vis[200005]; 
int comp[200005];

void dfs(int x){
	if(vis[x]) return;
	vis[x] = 1;
	for(auto &i : gph[x]) dfs(i);
	dfn.push_back(x);
}

void rdfs(int x, int p){
	if(comp[x]) return;
	comp[x] = p;
	for(auto &i : rev[x]) rdfs(i, p);
}

int main(){
	scanf("%d %d",&n,&m);
	p = m;
	for(int i=0; i<n; i++){
		vector<pi> v;
		for(int j=0; j<m; j++){
			int t;
			scanf("%d",&t);
			if(t != -1) v.emplace_back(t, j+1);
		}
		sort(v.begin(), v.end());
		for(int i=0; i<v.size(); ){
			int e = i;
			while(e < v.size() && v[e].first == v[i].first) e++;
			for(int j=i; j<e; j++){
				if(i != 0){
					gph[p].push_back(v[j].second);
					rev[v[j].second].push_back(p);
				}
				gph[v[j].second].push_back(p + 1);
				rev[p+1].push_back(v[j].second);
			}
			p++;
			i = e;
		}
	}
	for(int i=1; i<=p; i++){
		if(!vis[i]) dfs(i);
	}
	reverse(dfn.begin(), dfn.end());
	for(auto &i : dfn){
		if(!comp[i]) rdfs(i, ++piv);
	}
	if(piv != p){
		cout << -1;
		return 0;
	}
	vector<int> v;
	for(int i=1; i<=m; i++){
		v.push_back(comp[i]);
	}
	int rfunc[100005];
	sort(v.begin(), v.end());
	for(int i=1; i<=m; i++){
		rfunc[lower_bound(v.begin(), v.end(), comp[i]) - v.begin() + 1] = i;
	}
	for(int i=1; i<=m; i++){
		printf("%d ", rfunc[i]);
	}
}