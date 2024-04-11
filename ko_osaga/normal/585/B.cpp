#include<bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
const int MAXN = 105;

int n;
char str[3][MAXN];
bool vis[3][MAXN];

bool ok(int x, int y){
	if(x < 0 || x >= 3) return false;
	if(y >= n) return true;
	if(str[x][y] == '.') return true;
	return false;
}

bool dfs(int x, int y){
	if(y >= n) return true;
	if(vis[x][y]) return false;
	vis[x][y] = 1;
	for(int i=-1; i<=1; i++){
		if(ok(x, y+1) && ok(x+i, y+1) && ok(x+i, y+3) && dfs(x+i, y+3)){
			return true;
		}
	}
	return false;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		scanf("%d %*d",&n);
		for(int i=0; i<3; i++) cin >> str[i];
		memset(vis, 0, sizeof(vis));
		for(int i=0; i<3; i++){
			for(int j=0; j<n; j++){
				if(str[i][j] == 's'){
					puts(dfs(i, j) ? "YES" : "NO");
				}
			}
		}
	}
}