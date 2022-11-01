#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n, x;

vector<int> v[maxn];
int dep[maxn];
int ans;

/*void dfs(int i, int fa){
	bool tag = false;
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to == fa) continue;
		tag = true;
		dep[to] = dep[i] + 1, dfs(to, i);
	}
	if(!tag)  
}*/

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &x);
		for(int i = 1;i <= n;i++) v[i].clear();
		for(int i = 1;i < n;i++){
			int x, y;
			scanf("%d%d", &x, &y);
			v[x].push_back(y), v[y].push_back(x); 
		}
		if(v[x].size() <= 1){
			puts("Ayush");
			continue;
		}
		if(n & 1) puts("Ashish");
		else puts("Ayush");
	}
}