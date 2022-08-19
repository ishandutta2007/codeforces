#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;
const int MAXN = 200005;

vector<int> gph[MAXN];
int par[MAXN], n;

pi dfs(int x, int p){
	pi ret(0, x);
	for(auto &i : gph[x]){
		if(i == p) continue;
		par[i] = x;
		pi f = dfs(i, x);
		f.first++;
		ret = max(ret, f);
	}
	return ret;
}

int dfs2(int x, int p){
	vector<int> ans;
	for(auto &i : gph[x]){
		if(i == p) continue;
		ans.push_back(dfs2(i, x) + 1);
	}
	if(ans.empty()) return 0;
	if(*min_element(ans.begin(), ans.end()) != *max_element(ans.begin(), ans.end())){
		puts("-1");
		exit(0);
	}
	return ans[0];
}

int main(){
	scanf("%d",&n);
	for(int i=1; i<n; i++){
		int s, e;
		scanf("%d %d",&s,&e);
		gph[s].push_back(e);
		gph[e].push_back(s);
	}
	auto l = dfs(dfs(1, 0).second, -1);
	int d = l.first / 2;
	int pos = l.second;
	while(d){
		d--;
		pos = par[pos];
	}
	vector<int> v;
	for(auto &i : gph[pos]){
		v.push_back(dfs2(i, pos) + 1);
	}
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	if(v.size() > 2){
		puts("-1");
		return 0;
	}
	int r = 0;
	for(auto &i : v) r += i;
	while(r % 2 == 0) r >>= 1;
	cout << r;
}