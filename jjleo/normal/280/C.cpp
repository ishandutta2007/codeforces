#include <bits/stdc++.h>
#define maxn 100086
using namespace std;

int n;
vector<int> v[maxn];
int x, y;

double ans;

void dfs(int i, int fa, int dep){
	ans += 1.0 / dep;
	for(int j = 0;j < v[i].size();j++){
		if(v[i][j] == fa) continue;
		dfs(v[i][j], i, dep + 1);
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 1;i < n;i++){
		scanf("%d%d", &x, &y);
		v[x].push_back(y), v[y].push_back(x);
	}
	dfs(1, 0, 1);
	printf("%.10lf", ans);
}