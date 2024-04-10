#include <bits/stdc++.h>

using namespace std;

vector<pair<char, char> > v[123];

int n, len[2];
char s[2][60];
bool f[2][60][60][123];
int g[60][60];
char tmp[10];

int main(){
	scanf("%s%s%d", s[0] + 1, s[1] + 1, &n);
	while(n--){
		scanf("%s", tmp);
		v[tmp[0]].push_back({tmp[3], tmp[4]});
	}
	for(int x = 0;x <= 1;x++){
		len[x] = strlen(s[x] + 1);
		for(int i = 1;i <= len[x];i++) f[x][i][i][s[x][i]] = true;
		for(int l = 2;l <= len[x];l++){
			for(int i = 1;i + l - 1 <= len[x];i++){
				for(int j = i;j < i + l - 1;j++){
					for(int a = 'a';a <= 'z';a++){
						for(int k = 0;k < v[a].size();k++){
							f[x][i][i + l - 1][a] |= f[x][i][j][v[a][k].first] & f[x][j + 1][i + l - 1][v[a][k].second];
						}
					}
				}
			}
		}
	} 
	memset(g, 0x3f, sizeof(g));
	g[0][0] = 0;
	for(int i = 1;i <= len[0];i++){
		for(int j = 1;j <= len[1];j++){
			for(int ii = 0;ii < i;ii++){//debug:0  
				for(int jj = 0;jj < j;jj++){
					for(int a = 'a';a <= 'z';a++){
						if(f[0][ii + 1][i][a] & f[1][jj + 1][j][a]) g[i][j] = min(g[i][j], g[ii][jj] + 1); 
					}
				}
			}
			//printf("%d %d %d--\n", i, j, g[i][j]);
		}
	}
	printf("%d", g[len[0]][len[1]] == 0x3f3f3f3f ? -1 : g[len[0]][len[1]]);
}