#include <bits/stdc++.h>
#define maxn 300086

using namespace std;

int t;
int n;
char s[maxn];
int f[maxn], g[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%s", &n, s + 1);
		for(int i = 1;i <= n;i++){
			if(s[i] != s[i - 1]) f[i] = f[i - 1] + 1;
			else f[i] = 1;
		}
		g[n + 1] = 0;
		for(int i = n;i;i--){
			if(s[i] != s[i + 1]) g[i] = g[i + 1] + 1;
			else g[i] = 1;
		}
		for(int i = 0;i <= n;i++){
			int ans = 1;
			if(i){
				if(s[i] == 'L') ans += f[i];
			}
			if(i < n){
				if(s[i + 1] == 'R') ans += g[i + 1];
			}
			printf("%d ", ans);
		}
		puts("");
	}
}