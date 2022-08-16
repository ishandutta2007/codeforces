#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int l[N], pos[N];
vector<int> vec[N];
vector<int> con[N]; // directed graph
int must[N], mustnot[N], vis[N];

bool dfs(int s){
	vis[s] = 1;
	if(mustnot[s]) return 0;
	for(int v : con[s])
		if(!vis[v]){
			if(!dfs(v)) return 0;
		}
	return 1;
}

int main(){
	int n, m, x;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d", &l[i]);
		for(int j = 1; j <= l[i]; j++){
			scanf("%d", &x);
			vec[i].push_back(x);
		}
	}
	for(int i = 1; i <= n - 1; i++){
		bool done = 0;
		for(int j = 0; j < min(l[i], l[i + 1]); j++){
			if(vec[i][j] < vec[i + 1][j]){
				con[vec[i + 1][j]].push_back(vec[i][j]);
				done = 1;
				break;
			}
			else if(vec[i + 1][j] < vec[i][j]){
				must[vec[i][j]] = 1;
				mustnot[vec[i + 1][j]] = 1;
				done = 1;
				break;
			}
		}

		if(!done){
			if(l[i + 1] < l[i]){
				printf("No\n");
				return 0;
			}
		}
	}
	for(int s = 1; s <= m; s++){
		if((!vis[s]) && must[s]){
			if(!dfs(s)){
				printf("No\n");
				return 0;
			}
		}
	}
	printf("Yes\n");
	int k = 0;
	for(int i = 1; i <= m; i++) if(vis[i]) k++;
	printf("%d\n", k);	
	for(int i = 1; i <= m; i++) if(vis[i]) printf("%d ", i);
}