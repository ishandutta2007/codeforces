#include <bits/stdc++.h>
#define maxn 405

using namespace std;

int T;
char s[maxn], t[maxn];
int n, m;
int f[maxn][maxn];

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%s%s", s + 1, t + 1);
		n = strlen(s + 1), m = strlen(t + 1);
		int x = 0;
		for(int i = 1;i <= n;i++) if(s[i] == t[x + 1]) ++x;
		if(x == m){
			puts("YES");
			continue;
		}
		bool suc = false;
		for(int i = 1;i < m;i++){
			memset(f, -0x3f, sizeof(f)), f[0][0] = 0;
			for(int j = 0;j < n;j++){
				for(int k = 0;k <= i;k++){
					if(f[j][k] < 0) continue;
					if(t[k + 1] == s[j + 1]) f[j + 1][k + 1] = max(f[j + 1][k + 1], f[j][k]);
					f[j + 1][k] = max(f[j + 1][k], f[j][k]);
					if(t[i + f[j][k] + 1] == s[j + 1]) f[j + 1][k] = max(f[j + 1][k], f[j][k] + 1);
				}
			}
			if(f[n][i] == m - i){
				suc = true, puts("YES");
				break;
			}
		}
		if(!suc) puts("NO");
	}
}