#include <bits/stdc++.h>
#define maxn 3086

using namespace std;


int t;
int a[maxn];
long long f[maxn][maxn];

long long ans;

int n;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) f[i][j] = 0;
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		ans = 0;
		for(int i = 2;i <= n;i++){
			for(int j = 1;j < i - 1;j++) f[a[j]][a[i - 1]]++;
			for(int j = i + 1;j <= n;j++) ans += f[a[i]][a[j]];
		}
		printf("%lld\n", ans);
	}
}