#include <bits/stdc++.h>
#define maxn 300086

using namespace std;

int t;
int n;
int pos[maxn], mx[maxn];
int x;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) pos[i] = 0, mx[i] = 0;
		for(int i = 1;i <= n;i++){
			scanf("%d", &x);
			mx[x] = max(mx[x], i - pos[x]);
			pos[x] = i;
		}
		for(int i = 1;i <= n;i++) mx[i] = max(mx[i], n + 1 - pos[i]);
		for(int i = 1;i <= n;i++) a[i] = n + 1;
		for(int i = 1;i <= n;i++) a[mx[i]] = min(a[mx[i]], i);
		int ans = n + 1;
		for(int i = 1;i <= n;i++){
			ans = min(ans, a[i]);
			printf("%d ", ans == n + 1 ? -1 : ans);
		}
		puts("");
	}
}