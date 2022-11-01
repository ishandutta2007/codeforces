#include <bits/stdc++.h>
#define maxn 3005

using namespace std;

const int p = 998244353;

int n, m;
char s[maxn], t[maxn];
int f[maxn][maxn];
int ans;

int main(){
	scanf("%s%s", s + 1, t + 1);
	n = strlen(s + 1), m = strlen(t + 1);
	f[n + 1][0] = 1;
	for(int i = n;i;i--){
		for(int j = 0;j <= n - i + 1;j++){
			if(j > 0){
				if(j > m || s[i] == t[j]){
					f[i][j] = (f[i][j] + f[i + 1][j - 1]) % p;
				}
			}
			if(j == 0 && i > m) f[i][j] = n - i + 2;
			else if(n - (n - i + 1 - j) + 1 > m || t[n - (n - i + 1 - j) + 1] == s[i]) f[i][j] = (f[i][j] + f[i + 1][j]) % p;
			//printf("%d %d %d--\n", i, j, f[i][j]);
		}
	}
	for(int i = 0;i <= n;i++) ans = (ans + f[1][i]) % p;
	printf("%d", ans);
}