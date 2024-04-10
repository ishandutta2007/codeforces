#include <bits/stdc++.h>
#define maxn 2086

using namespace std;

int n;

vector<int> v[maxn];
int x;
int a[maxn];
int siz[maxn];
vector<double> V[maxn];
int root;
double d[maxn], b[maxn];

void dfs(int i){
	siz[i] = 1;
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		dfs(to);
		siz[i] += siz[to];
		for(int k = 0;k < V[to].size();k++) V[i].push_back(V[to][k]);
	}
	if(siz[i] <= a[i]) printf("NO"), exit(0);
	mt19937 myrand(i);
	if(siz[i] == 1) d[i] = 1.0 * myrand();
	else{
		sort(V[i].begin(), V[i].end());
		if(a[i] == 0) d[i] = V[i][0] - abs(myrand());
		else if(a[i] == siz[i] - 1) d[i] = V[i][V[i].size() - 1] + abs(myrand());
		else d[i] = (V[i][a[i] - 1] + V[i][a[i]]) / 2;
	}
	V[i].push_back(d[i]);
}

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++){
		scanf("%d%d", &x, &a[i]);
		if(!x) root = i;
		else v[x].push_back(i);
	}
	dfs(root);
	puts("YES");
	for(int i = 1;i <= n;i++) b[i] = d[i];
	sort(b + 1, b + 1 + n);
	for(int i = 1;i <= n;i++) printf("%d ", lower_bound(b + 1, b + 1 + n, d[i]) - b);
	
	
}