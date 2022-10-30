#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		int mn = 100, ans = 0;
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]), mn = min(mn, a[i]);
		for(int i = 1;i <= n;i++) ans += a[i] != mn;
		printf("%d\n", ans);
	}
}