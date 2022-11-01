#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t;
int n;
int a[maxn];
int f[maxn][2];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		for(int i = 0;i <= n;i++) f[i][0] = f[i][1] = 1e9;
		f[0][1] = 0;
		for(int i = 1;i <= n;i++){
			f[i][0] = min(f[i][0], f[i - 1][1] + a[i]);
			if(i > 1) f[i][0] = min(f[i][0], f[i - 2][1] + a[i] + a[i - 1]);
			f[i][1] = min(f[i][1], f[i - 1][0]);
			if(i > 1) f[i][1] = min(f[i][1], f[i - 2][0]);
		}
		printf("%d\n", min(f[n][0], f[n][1]));
	}
}