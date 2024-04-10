#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

vector<int> pred,cnt;
vector<double> ans;
vector<vector<int>> g;

int count(int v)
{
	int res = 1;
	for(auto u: g[v]){
		res += count(u);
	}
	return cnt[v] = res;
}

void dfs(int v){
	if(v!=0){
		ans[v] = ans[pred[v]] + 1 + 0.5 * (cnt[pred[v]]-cnt[v]-1);
	}
	for(auto u: g[v]){
		dfs(u);
	}
}

int main()
{
	int n;
	cin >> n;
	pred.resize(n,-1);
	cnt.resize(n,0);
	ans.resize(n,0);
	ans[0] = 1;
	g.resize(n,vector<int>());
	int a,b;
	for(int i=1;i<n;i++){
		cin >> a;
		pred[i] = a-1;
		g[a-1].push_back(i);
	}
	count(0);
	dfs(0);
	cout << ans[0];
	for(int i=1;i<n;i++){
		cout << " " << ans[i];
	}
}