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

vector<int> gph[105];
int n, a[105], b[105];

bool vis[105];
vector<int> elem, dfn;

void dfs(int x){
	if(vis[x]) return;
	vis[x] = 1;
	elem.push_back(a[x]);
	dfn.push_back(x);
	for(auto &i : gph[x]){
		dfs(i);
	}
}
int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	for(int i=0; i<n; i++){
		cin >> b[i];
		for(int j=0; j<n; j++){
			if(abs(j - i) == b[i]){
				gph[i].push_back(j);
				gph[j].push_back(i);
			}
		}
	}
	for(int i=0; i<n; i++){
		if(vis[i]) continue;
		elem.clear();
		dfn.clear();
		dfs(i);
		sort(elem.begin(), elem.end());
		sort(dfn.begin(), dfn.end());
		int p = 0;
		for(auto &i : dfn){
			a[i] = elem[p++];
		}
	}
	puts(is_sorted(a, a+n) ? "YES" : "NO");
}