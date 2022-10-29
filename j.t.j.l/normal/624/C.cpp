#include<bits/stdc++.h>

using namespace std;

const int MAXN = 600;

int a[MAXN][MAXN];
int vis[MAXN];
vector<int> E[MAXN];

int main(){
	int n, m;
	cin>>n>>m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			a[i][j] = (i == j);
	for(int i = 1;  i<= n; i++)
		E[i].clear();
	for(int i = 1; i <= m; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		E[x].push_back(y);
		E[y].push_back(x);
		a[x][y] = a[y][x] = 1;
	}
	for(int i = 1; i <= n; i++)
		vis[i] = -1;
	for(int i = 1; i <= n; i++)
		if (E[i].size() == n - 1)
			vis[i] = 2;
	int flag = -1;
	for(int i = 1; i <= n; i++)
		if (vis[i] == -1){
			flag = i;
			break;
		}
	if (flag == -1){
		puts("Yes");
		for(int i = 1; i <= n; i++)
			printf("%c", 'a' + vis[i] - 1);
		puts("");
		return 0;
	}
	vis[flag] = 1;
	for(int i = 0; i < E[flag].size(); i++)
		if (vis[E[flag][i]] == -1)
			vis[E[flag][i]] = 1;
	for(int i = 1; i <= n; i++)
		if (vis[i] == -1){
			vis[i] = 3;
		}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++){
			if (a[i][j] && abs(vis[i] - vis[j]) > 1){
				puts("No");
				return 0;
			}
			if (!a[i][j] && abs(vis[i] - vis[j]) <= 1){
				puts("No");
				return 0;
			}
		}
	puts("Yes");
	for(int i = 1; i <= n; i++)
		printf("%c", 'a' + vis[i] - 1);
	puts("");
	return 0;
}