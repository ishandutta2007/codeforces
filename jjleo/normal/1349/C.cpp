#include <bits/stdc++.h>
#define maxn 1086

using namespace std;

int n, m, t;
char s[maxn][maxn];
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
int a[maxn][maxn]; 
int x, y;
long long z;
bool tag;


queue<pair<int, int> > q;

int main(){
	scanf("%d%d%d", &n, &m, &t);
	for(int i = 1;i <= n;i++) scanf("%s", s[i] + 1);
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			for(int k = 0;k < 4;k++){
				int ii = i + dx[k], jj = j + dy[k];
				if(ii && ii <= n && jj && jj <= m && s[ii][jj] == s[i][j]){
					a[i][j] = 1, q.push({i, j});
					break;
				}
			}
		}
	}
	if(q.empty()) tag = true;
	while(!q.empty()){
		pair<int, int> p = q.front();q.pop();
		for(int k = 0;k < 4;k++){
			int i = p.first + dx[k], j = p.second + dy[k];
			if(i && i <= n && j && j <= m && !a[i][j]){
				a[i][j] = a[p.first][p.second] + 1, q.push({i, j});
			}
		}
	}
	while(t--){
		scanf("%d%d%lld", &x, &y, &z);
		if(tag || z < a[x][y]) printf("%c\n", s[x][y]);
		else printf("%c\n", (z - a[x][y]) & 1 ? s[x][y] : (((s[x][y] - '0') ^ 1) + '0'));
	}
}