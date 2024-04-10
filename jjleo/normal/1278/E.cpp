#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

int n;
int x, y;
vector<int> v[maxn];
int siz[maxn];
bool tag[maxn];
int pos[maxn];
int ans[maxn][2];

void dfs(int i, int fa){
	int l = --pos[fa];
	int cnt = v[i].size() - (fa != 0);
	x += cnt + 1;
	pos[i] = x;
	int r = x;
	ans[i][0] = l, ans[i][1] = r;
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to == fa) continue;
		dfs(to, i);
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 1;i < n;i++){
		scanf("%d%d", &x, &y);
		v[x].push_back(y), v[y].push_back(x); 
	}
	pos[0] = 2, x = 1;
	dfs(1, 0);
	for(int i = 1;i <= n;i++) printf("%d %d\n", ans[i][0], ans[i][1]);
}