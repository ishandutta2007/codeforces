#include <bits/stdc++.h>
#define maxn 200086
using namespace std;

vector<int> v1[maxn], v2[maxn];


int dep[maxn];
int cnt, ans[maxn][3];

void dfs(int i){
	for(int j = 0;j < v1[i].size();j++){
		int to = v1[i][j];
		if(!dep[to]) dep[to] = dep[i] + 1, dfs(to);
		else if(dep[to] < dep[i]) v2[i].push_back(to);
	}
	if(v2[i].size() & 1){
		if(v2[i].size() >= 2 && dep[v2[i][v2[i].size() - 1]] > dep[i]){
			for(int j = 0;j < v2[i].size();j++){
				if(dep[v2[i][j]] < dep[i]){
					swap(v2[i][v2[i].size() - 1], v2[i][j]);
					break;
				}
			}
		}
		v2[v2[i][v2[i].size() - 1]].push_back(i), v2[i].pop_back();
	}
	for(int j = 0;j < v2[i].size();j += 2) cnt++, ans[cnt][0] = v2[i][j], ans[cnt][1] = i, ans[cnt][2] = v2[i][j + 1];
}

int n, m;
int x, y;

int main(){
	scanf("%d%d", &n, &m);
	while(m--){
		scanf("%d%d", &x, &y);
		v1[x].push_back(y), v1[y].push_back(x);//debug:12 
	}
	for(int i = 1;i <= n;i++) if(!dep[i]) dep[i] = 1, dfs(i);//debug: 
	printf("%d\n", cnt);
	for(int i = 1;i <= cnt;i++) printf("%d %d %d\n", ans[i][0], ans[i][1], ans[i][2]);
}