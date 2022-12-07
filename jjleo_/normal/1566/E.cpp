#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t, n;
int x, y;
vector<int> v[maxn];
int leaf[maxn], bud[maxn], ans;

void dfs(int i, int fa){
	leaf[i] = bud[i] = true;
	int cnt = 0, tot = 0, lcnt = 0;
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to == fa) continue;
		leaf[i] = false;
		dfs(to, i);
		bud[i] &= leaf[to];
		cnt += bud[to];
		lcnt += leaf[to];
		tot++; 
	}
	if(leaf[i]) bud[i] = false;
	ans += leaf[i];
	if(cnt && tot == cnt){
		leaf[i] = true;
		cnt--;
	}
	if(cnt && lcnt && cnt + lcnt == tot){
		bud[i] = true;
	}
	ans -= cnt;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) v[i].clear();
		for(int i = 1;i < n;i++){
			scanf("%d%d", &x, &y);
			v[x].push_back(y), v[y].push_back(x);
		}
		ans = 0, dfs(1, 0);
		printf("%d\n", ans);
	}
}