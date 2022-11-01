#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t, n;
char s[maxn];
int a[maxn];
int f[maxn][2];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%s", &n, s + 1);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		f[n + 1][0] = 0, f[n + 1][1] = -2e9;
		for(int i = n;i;i--){
			if(s[i] == '1'){
				f[i][0] = f[i + 1][0] + a[i];
				f[i][1] = max(f[i + 1][0], f[i + 1][1] + a[i]);
			}else{
				f[i][0] = max(f[i + 1][0], f[i + 1][1] + a[i]);
				f[i][1] = -2e9;
			}
		}
		printf("%d\n", max(f[1][0], f[1][1]));
	}
}