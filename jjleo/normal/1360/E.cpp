#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;
char s[100][100];

int dx[2] = {0, 1}, dy[2] = {1, 0};

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%s", s[i] + 1);
		bool suc = true;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				if(s[i][j] == '1'){
					for(int k = 0;k <= 1;k++){
						int ii = i + dx[k], jj = j + dy[k];
						if(!(ii && ii <= n && jj && jj <= n)) break;
						if(s[ii][jj] == '1') break;
						if(k == 1) suc = false;
					}
					if(!suc) break;
				}
			}
			if(!suc) break;
		}
		puts(suc ? "YES" : "NO");
	}
}