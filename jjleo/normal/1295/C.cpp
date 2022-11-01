#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int n, m;
int T;
char s[maxn], t[maxn];
int f[maxn][26];

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%s%s", s + 1, t + 1);
		n = strlen(s + 1), m = strlen(t + 1);
		for(int i = 1;i <= n + 1;i++) memset(f[i], 0, sizeof(f[i]));
		for(int i = n;i;i--){
			for(int j = 0;j < 26;j++){
				f[i][j] = f[i + 1][j];
			}
			f[i][s[i] - 'a'] = i;
		}
		int ans = 1, now = 1;
		for(int i = 1;i <= m;i++){
			if(!f[1][t[i] - 'a']){
				ans = -1;
				break;
			}
			if(!f[now][t[i] - 'a']) now = 1, ans++;
			now = f[now][t[i] - 'a'] + 1;
		}
		printf("%d\n", ans);
	}
}