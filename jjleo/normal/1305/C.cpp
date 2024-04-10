#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int n, m;
int a[maxn];
int ans = 1;

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	if(n > m) return printf("0"), 0;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j < i;j++) ans = 1ll * ans * abs(a[i] - a[j]) % m; 
	}
	printf("%d", ans);
}