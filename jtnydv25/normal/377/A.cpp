#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))

const int N = 505 * 505;
const int M = 505;

inline int get(int i, int j){
	return M * i + j;
}

inline int getI(int x){ return x  / M;}
inline int getJ(int x){ return x % M;}
vector<int> con[N];
int vis[N];
int vis2[505][505];
void dfs(int s, int req, int & done){
	vis[s] = 1;
	vis2[getI(s)][getJ(s)] = 1;
	done++;
	for(int v : con[s]){
		if(!vis[v] && done < req)
			dfs(v, req, done);
	}
}
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char s[505][505];
bool valid[505][505];
int main(){
	int n, m, k;
	sd(n); sd(m); sd(k);
	for(int i = 0; i < n; i++){
		scanf("%s", s[i]);
		for(int j = 0; j < m; j++)
			if(s[i][j] == '.')
				valid[i][j] = 1;
	}
	int x, y, nodes = 0;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++)
			if(valid[i][j]){
				for(int k = 0; k < 4; k++){
					int i1 = i + dx[k], j1 = j + dy[k];
					if(i1 >= 0 && i1 < n && j1 >= 0 && j1 < m && valid[i1][j1])
						con[get(i, j)].push_back(get(i1, j1));
				}
				x = i, y = j; nodes++;
			}
	}
	int done = 0;
	dfs(get(x, y), nodes - k, done);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(!vis2[i][j] && s[i][j] == '.') s[i][j] = 'X';
	for(int i = 0; i < n; i++) printf("%s\n", s[i]);
}