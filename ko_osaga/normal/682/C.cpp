#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
typedef vector<int> vi;

int n, a[100005];
vector<pi> gph[100005];
int p[100005], c[100005];

lint dep[100005], mindep[100005];
bool chk[100005];

void dfs(int x, int p){
	if(mindep[x] < dep[x] - a[x]){
		chk[x] = 1;
	}
	mindep[x] = min(mindep[x], dep[x]);
	for(auto &i : gph[x]){
		if(i.second == p) continue;
		dep[i.second] = dep[x] + i.first;
		mindep[i.second] = min(mindep[i.second], mindep[x]);
		dfs(i.second, x);
	}
}

int dfs2(int x, int p){
	if(chk[x]) return 0;
	int ret = 1;
	for(auto &i : gph[x]){
		if(i.second == p) continue;
		ret += dfs2(i.second, x);
	}
	return ret;
}

int main(){
	memset(mindep, 0x3f, sizeof(mindep));
	cin >> n;
	for(int i=1; i<=n; i++) scanf("%d",&a[i]);
	for(int i=2; i<=n; i++){
		scanf("%d %d",&p[i], &c[i]);
		gph[p[i]].push_back({c[i], i});
	}
	dfs(1, -1);
	cout << n - dfs2(1, -1);
}