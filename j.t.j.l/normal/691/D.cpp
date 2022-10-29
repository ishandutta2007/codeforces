#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 10;

int a[MAXN], fa[MAXN];

int getfather(int x){
	if (fa[x] == x)
		return x;
	else
		return fa[x] = getfather(fa[x]);
}

vector<int> E[MAXN], F[MAXN];

int main(){
	int n, m;
	cin>>n>>m;
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]), fa[i] = i;
	for(int i = 1; i <= m; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		int p = getfather(x);
		int q = getfather(y);
		fa[p] = q;
	}
	for(int i = 1; i <= n; i++)
		fa[i] = getfather(i);
	for(int i = 1; i <= n; i++){
		E[i].clear(); F[i].clear();
	}
	for(int i = 1; i <= n; i++){
		E[fa[i]].push_back(-a[i]);
		F[fa[i]].push_back(i);
	}
	for(int i = 1; i <= n; i++)
		if (E[i].size()){
			sort(E[i].begin(), E[i].end());
			for(int j = 0; j < E[i].size(); j++)
				a[F[i][j]] = -E[i][j];
		}
	for(int i = 1; i <= n; i++)
		printf("%d%c", a[i], " \n"[i == n]);
	return 0;
}