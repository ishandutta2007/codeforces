#include <bits/stdc++.h>
#define maxn 55

using namespace std;

int t, n, m;
char s[maxn][maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 1;i <= n;i++) scanf("%s", s[i] + 1);
		int id = -1;
		bool tag = false;
		for(int i = 1;i <= n && !tag;i++){
			for(int j = 1;j <= m && !tag;j++){
				if(s[i][j] == 'R'){
					if(id == -1) id = (i + j) & 1;
					else if(id != ((i + j) & 1)) tag = true;
				}else if(s[i][j] == 'W'){
					if(id == -1) id = (i + j + 1) & 1;
					else if(id != ((i + j + 1) & 1)) tag = true;
				}
			}
		}
		if(tag){
			puts("NO");
			continue;
		}
		puts("YES");
		if(id == -1) id = 0;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++) printf(((i + j) & 1) == id ? "R" : "W");
			puts("");
		}
	}
}