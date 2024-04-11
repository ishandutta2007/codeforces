#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

int n, m, s;
char str[555][555];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
bool vis[555][555];

vector<pi> ord;

void dfs(int x, int y){
	if(vis[x][y] || str[x][y] == '#') return;
	vis[x][y] = 1;
	ord.push_back(pi(x, y));
	for(int i=0; i<4; i++){
		if(x + dx[i] < 0 || x + dx[i] >= n || y + dy[i] < 0 || y + dy[i] >= m) continue;
		dfs(x + dx[i], y + dy[i]);
	}
}

int main(){
	cin >> n >> m >> s;
	for(int i=0; i<n; i++) cin >> str[i];
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(str[i][j] == '.'){
				dfs(i, j);
				reverse(ord.begin(), ord.end());
				for(int k=0; k<s; k++){
					str[ord[k].first][ord[k].second] = 'X';
				}
				for(int i=0; i<n; i++) cout << str[i] << endl;
				return 0;
			}
		}
	}
}