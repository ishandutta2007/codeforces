#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t;
char s[maxn];
int n;
bool tag[3];
int f[maxn][2], g[maxn][2];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%s", s + 1);
		memset(tag, 0, sizeof(tag));
		n = strlen(s + 1);
		for(int i = 1;i <= n;i++) tag[s[i] - '1'] = true;
		if(!tag[0] || !tag[1] || !tag[2]){
			puts("0");
			continue;
		}
		int ans = n;
		int x = -n, y = -n;
		for(int i = 1;i <= n;i++){
			if(s[i] == '1'){
				f[i][0] = x, f[i][1] = y;
			}else{
				if(s[i] == '2') x = i;
				else y = i;
			}
		}
		x = y = n + n;
		for(int i = n;i;i--){
			if(s[i] == '1'){
				g[i][0] = x, g[i][1] = y;
			}else{
				if(s[i] == '2') x = i;
				else y = i;
			}
		}
		for(int i = 1;i <= n;i++){
			if(s[i] == '1'){
				ans = min(ans, i - min(f[i][0], f[i][1]) + 1);
				ans = min(ans, max(g[i][0], g[i][1]) - i + 1);
				ans = min(ans, g[i][0] - f[i][1] + 1);
				ans = min(ans, g[i][1] - f[i][0] + 1);
			}
		}
		printf("%d\n", ans);
	}
}