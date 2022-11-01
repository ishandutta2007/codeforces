#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n;
int a[maxn], b[maxn], x;

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", &x), a[x] = i;
	for(int i = 1;i <= n;i++) scanf("%d", &x), b[a[x]] = i;
	int mx = 0, ans = 0;
	for(int i = 1;i <= n;i++){
		ans += mx > b[i];
		mx = max(mx, b[i]); 
	}
	printf("%d", ans);
}