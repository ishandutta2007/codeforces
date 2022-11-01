#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		int x = 0;
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]), x += a[i];
		int ans = 0;
		for(int i = n - x + 1;i <= n;i++) ans += a[i] == 0;
		printf("%d\n", ans);
	}
}