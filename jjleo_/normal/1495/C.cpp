#include <bits/stdc++.h>
#define maxn 505

using namespace std;

int t, n, m;
char s[maxn][maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 1;i <= n;i++) scanf("%s", s[i] + 1);
		for(int j = 1;j <= m;j += 3){
			for(int i = 1;i <= n;i++) s[i][j] = 'X';
		}
		for(int j = 1;j <= m;j += 3){
			if(j + 3 > m){
				for(int i = 1;i <= n;i++){
					if(j + 2 <= m && s[i][j + 2] == 'X'){
						s[i][j + 1] = 'X';
					}
				}
			}else{
				bool tag = false;
				for(int i = 1;i <= n && !tag;i++){
					if(s[i][j + 1] == 'X'){
						tag = true;
						s[i][j + 2] = 'X';
					}else if(s[i][j + 2] == 'X'){
						tag = true;
						s[i][j + 1] = 'X';
					}
				}	
				if(!tag) s[1][j + 1] = s[1][j + 2] = 'X';
			}
		}
		for(int i = 1;i <= n;i++) printf("%s\n", s[i] + 1);
	}
}