#include <bits/stdc++.h>
#define maxn 505

using namespace std;

int n, m;
char s[maxn][maxn];
vector<int> v[maxn * maxn];
int c[maxn * maxn];
const int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

void dfs(int i){
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(!c[to]) c[to] = 5 - c[i], dfs(to);
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++) scanf("%s", s[i] + 1);
	for(int i = 1;i <= n;i++) for(int j = 1;j <= m;j++) if(s[i][j] == 'X'){
		vector<int> w;
		for(int k = 0;k < 4;k++){
			int ii = i + dx[k], jj = j + dy[k];
			if(s[ii][jj] == '.') w.push_back((ii - 1) * m + jj);
		}
		if(w.size() & 1) return printf("NO"), 0;
		for(int k = 0;k < w.size();k++){
			int kk = k + 1;
			if(kk == w.size()) kk = 0;
			v[w[k]].push_back(w[kk]), v[w[kk]].push_back(w[k]);
		}
	}
	for(int i = 1;i <= n;i++) for(int j = 1;j <= m;j++) if(s[i][j] == '.' && !c[(i - 1) * m + j]) c[(i - 1) * m + j] = 1, dfs((i - 1) * m + j);
	puts("YES");
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(s[i][j] == '.') printf("%d ", c[(i - 1) * m + j]);
			else{
				int sum = 0;
				for(int k = 0;k < 4;k++){
					int ii = i + dx[k], jj = j + dy[k];
					if(s[ii][jj] == '.') sum += c[(ii - 1) * m + jj];
				}
				printf("%d ", sum);
			}
		}
		puts("");
	}
}