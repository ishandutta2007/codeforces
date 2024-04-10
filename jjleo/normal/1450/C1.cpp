#include <bits/stdc++.h>
#define maxn 305

using namespace std;

int t;
int n;
char s[maxn][maxn];
vector<pair<int, int> > v[3];

int main(){
	scanf("%d", &t);
	while(t--){
		for(int i = 0;i < 3;i++) v[i].clear();
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%s", s[i] + 1);
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				if(s[i][j] == 'X') v[(i + j) % 3].push_back({i, j});
			}
		}
		int x = 0;
		for(int i = 1;i <= 2;i++) if(v[i].size() < v[x].size()) x = i;
		for(int i = 0;i < v[x].size();i++) s[v[x][i].first][v[x][i].second] = 'O';
		for(int i = 1;i <= n;i++) printf("%s\n", s[i] + 1);
	}
}