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
typedef pair<lint, int> pi;
#define div fuck

// l, r  pick ->  
// l, r  not pick ->  

int n, m;
vector<pi> gph[100005];

int col[100005];
bool bad;

vector<pi> v;

void dfs(int x, int c, int v){
	if(col[x]){
		if(col[x] != c) bad = 1;
		return;
	}
	col[x] = c;
	::v.push_back(pi(col[x], x));
	for(auto &i : gph[x]){
		if(i.second != v) dfs(i.first, 3-c, v);
		else dfs(i.first, c, v);
	}
}

int main(){
	cin >> n >> m;
	for(int i=0; i<m; i++){
		int s, e;
		char x[5];
		scanf("%d %d %s",&s,&e,x);
		if(*x == 'B'){
			gph[s].emplace_back(e, 1);
			gph[e].emplace_back(s, 1);
		}
		else{
			gph[s].emplace_back(e, 0);
			gph[e].emplace_back(s, 0);
		}
	}
	// 1. Blue is the answer and we should flip either two of reds
	vector<vector<int>> dap;
	for(int t=0; t<2; t++){
		bad= 0;
		vector<int> tmp;
		v.clear();
		memset(col, 0, sizeof(col));
		for(int i=1; i<=n; i++){
			if(!col[i]){
				v.clear();
				dfs(i, 1, t);
				int c1 = 0, c2 = 0;
				for(auto &j : v){
					if(j.first == 1) c1++;
					else c2++;
				}
				if(c1 > c2){
					for(auto &j : v){
						if(j.first == 2) tmp.push_back(j.second);
					}
				}
				else{
					for(auto &j : v){
						if(j.first == 1) tmp.push_back(j.second);
					}
				}
			}
		}
		if(!bad){
			dap.push_back(tmp);
		}
	}
	sort(dap.begin(), dap.end(), [&](const vector<int> &v, const vector<int> &w){
		return v.size() < w.size();
	});
	if(dap.empty()){
		cout << -1;
		return 0;
	}
	printf("%d\n",dap[0].size());
	for(auto &i : dap[0]) printf("%d ",i);
}