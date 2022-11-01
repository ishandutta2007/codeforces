#include <bits/stdc++.h>
#define maxn 100

using namespace std;

int t, n, m, r, c;
char s[maxn][maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d%d", &n, &m, &r, &c);
		for(int i = 1;i <= n;i++) scanf("%s", s[i] + 1);
		int x = 0;
		for(int i = 1;i <= n;i++) for(int j = 1;j <= m;j++) x += s[i][j] == 'B';
		if(x == 0){
			puts("-1");
			continue;
		}
		if(s[r][c] == 'B'){
			puts("0");
			continue;
		}
		x = 0;
		for(int i = 1;i <= n;i++) if(s[i][c] == 'B') x = 1;
		for(int j = 1;j <= m;j++) if(s[r][j] == 'B') x = 1;
		if(x){
			puts("1");
			continue;
		}
		puts("2");
	}
}