#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;

vector<int> gph[100005];
int n;
int sz[100005];
double ans[100005];

void solve(int x, double c){
	ans[x] = c;
	for(auto &i : gph[x]){
		double d = (sz[x] - sz[i] - 1) * 0.5;
		solve(i, c + 1 + d);
	}
}

void dfs(int x){
	sz[x] = 1;
	for(auto &i : gph[x]){
		dfs(i);
		sz[x] += sz[i];
	}
}

int p[100005];

int main(){
	cin >> n;
	for(int i=2; i<=n; i++){
		scanf("%d",&p[i]);
		gph[p[i]].push_back(i);
	}
	dfs(1);
	solve(1, 1);
	for(int i=1; i<=n; i++) printf("%.2f ", ans[i]);
}