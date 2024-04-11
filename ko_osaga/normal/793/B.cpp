#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;
const int MAXN = 500005;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int n, m;
char str[1005][1005];
bool vis[1005][1005][4][3];

bool ok(int x, int y, int d, int c){
	if(x < 0 || x >= n || y < 0 || y >= m || str[x][y] == '*') return 0;
	if(str[x][y] == 'T') return 1;
	if(vis[x][y][d][c]) return 0;
	vis[x][y][d][c] = 1;
	if(ok(x + dx[d], y + dy[d], d, c)) return 1;
	for(int i=0; i<4; i++){
		if(i == d) continue;
		if(c > 0 && ok(x + dx[i], y + dy[i], i, c-1)) return 1;
	}
	return 0;
}

int main(){
	cin >> n >> m;
	for(int i=0; i<n; i++){
		cin >> str[i];
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(str[i][j] == 'S'){
				for(int k=0; k<4; k++){
					if(ok(i, j, k, 2)){
						puts("YES");
						return 0;
					}
				}
				puts("NO");
				return 0;
			}
		}
	}
}