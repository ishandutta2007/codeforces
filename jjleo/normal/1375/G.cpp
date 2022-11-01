#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int n;
vector<int> v[maxn];
int cnt[maxn], col[maxn];
int x, y;

void dfs(int i, int fa){
	cnt[col[i] = col[fa] ^ 1]++;
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
	dfs(1, 0);
	printf("%d", min(cnt[0], cnt[1]) - 1);
}