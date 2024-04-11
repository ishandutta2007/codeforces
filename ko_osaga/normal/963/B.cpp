#include <bits/stdc++.h>
const int MAXN = 200005;
const int mod = 1e9 + 9;
using namespace std;
using lint = long long;
using pi = pair<int, int>;

int n;
vector<int> gph[MAXN];
int par[MAXN];
int sz[MAXN];
int evenCnt[MAXN];
int mark[MAXN];

void dfs(int x, int p){
	sz[x] = 1;
	for(auto &i : gph[x]){
		if(i == p) continue;
		dfs(i, x);
		par[i] = x;
		sz[x] += sz[i];
		if(sz[i] % 2 == 0) evenCnt[x]++;
		if(sz[i] % 2 == 1) evenCnt[i]++;
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		int p;
		scanf("%d",&p);
		if(p != 0){
			gph[i].push_back(p);
			gph[p].push_back(i);
		}
	}
	if(n % 2 == 0){
		puts("NO");
		return 0;
	}
	dfs(1, -1);
	set<int> s;
	for(int i=1; i<=n; i++){
		if(evenCnt[i] == 0) s.insert(i);
	}
	vector<int> ret;
	while(!s.empty()){
		int x = *s.begin();
		s.erase(x);
		ret.push_back(x);
		mark[x] = 1;
		for(auto &i : gph[x]){
			if(mark[i]) continue;
			evenCnt[i]--;
			if(evenCnt[i] == 0) s.insert(i);
		}
	}
	if(ret.size() != n) puts("NO");
	else{
		puts("YES");
		for(auto &i : ret) printf("%d\n", i);
	}
}