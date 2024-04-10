#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 10;
const int MM = 1e9 + 7;
typedef long long ll;
typedef pair<int, int> PII;

vector<int> E[MAXN];
vector<int> U;

void dfs(int p, int fa, int dep){
	int flag = 1;
	for(int i = 0; i < E[p].size(); i++)
		if (E[p][i] != fa){
			flag = 0;
			dfs(E[p][i] , p, dep + 1);
		}
	if (flag){
		U.push_back(dep);
	}
}

ll work(int u){
	U.clear();
	dfs(u, 1, 0);
	/*
	for(int i = 0; i < E[u].size(); i++)
		if (E[u][i] != 1){
			dfs(E[u][i], u, 0);
		}*/
//	cout<<u<<endl;
//	for(int i = 0; i < U.size(); i++)
//		cout<<U[i]<<' '; cout<<endl;
	sort(U.begin(), U.end());
	int cnt = U[0];
	for(int i = 1; i < U.size(); i++)
		cnt = max(cnt + 1, U[i]);
	return cnt;
}

int main(){
	int n;
	cin>>n;
	for(int i = 1; i < n; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		E[x].push_back(y);
		E[y].push_back(x);
	}
	ll ans = 0;
	for(int i = 0; i < E[1].size(); i++){
		ans = max(ans, work(E[1][i]));
	}
	cout<<ans + 1<<endl;
	return 0;
}