#include <bits/stdc++.h>
#define maxn 186

using namespace std;

int t;
int n, m;
char s[maxn][maxn];
bool tag;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 1;i <= n;i++) scanf("%s", s[i] + 1);
		tag = false;
		int x = true;
		for(int i = 1;i <= n;i++) for(int j = 1;j <= m;j++) tag |= s[i][j] == 'A', x &= s[i][j] == 'A';
		if(x){
			puts("0");
			continue;
		}
		if(!tag){
			puts("MORTAL");
			continue;
		}
		int ans = 4;
		for(int i = 1;i <= n;i++){
			bool x = true;
			for(int j = 1;j <= m;j++) x &= s[i][j] == 'A';
			if(x){
				if(i == 1 || i == n) ans = min(ans, 1);
				else ans = min(ans, 2);
			}
		}
		for(int j = 1;j <= m;j++){
			bool x = true;
			for(int i = 1;i <= n;i++) x &= s[i][j] == 'A';
			if(x){
				if(j == 1 || j == m) ans = min(ans, 1);
				else ans = min(ans, 2);
			}
		}
		if(s[1][1] == 'A' || s[1][m] == 'A' || s[n][1] == 'A' || s[n][m] == 'A'){
			ans = min(ans, 2);
		}
		for(int i = 1;i <= n;i++){
			if(s[i][1] == 'A' || s[i][m] == 'A'){
				ans = min(ans, 3);
			}
		}
		for(int j = 1;j <= m;j++){
			if(s[1][j] == 'A' || s[n][j] == 'A'){
				ans = min(ans, 3);
			}
		}
		printf("%d\n", ans);
	}
}