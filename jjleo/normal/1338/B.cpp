#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n;
vector<int> v[maxn];
int x, y;

int dep[maxn];
bool odd, even, leaf[maxn];
int ans;

void dfs(int i, int fa){
	dep[i] = dep[fa] + 1;
	int sum = -1;
	for(int j = 0;j < v[i].size();j++){
		if(v[i][j] != fa){
			leaf[i] = false;
			dfs(v[i][j], i);
			if(leaf[v[i][j]]) ++sum;
		}
	}
	if(fa == 1 && v[fa].size() == 1) ++sum;
	if(sum > 0) ans -= sum;
	if(leaf[i] && (dep[i] & 1)) odd = true;
	if(leaf[i] && !(dep[i] & 1)) even = true;
} 

int main(){
	scanf("%d", &n);
	ans = n - 1;
	for(int i = 1;i < n;i++){
		scanf("%d%d", &x, &y);
		v[x].push_back(y), v[y].push_back(x);
	}
	for(int i = 1;i <= n;i++) leaf[i] = true;
	dep[0] = -1;
	dfs(1, 0);
	if(v[1].size() == 1) even = true;
	printf("%d %d", odd && even ? 3 : 1, ans);
}