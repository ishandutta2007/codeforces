#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int n;
int a[maxn], b[maxn], c[maxn];
int x;

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", &x), a[x] = i;
	for(int i = 1;i <= n;i++) scanf("%d", &b[i]);
	for(int i = 1;i <= n;i++){
		if(a[b[i]] >= i) c[a[b[i]] - i]++;
		else c[n - (i - a[b[i]])]++;
	}
	int ans = 0;
	for(int i = 0;i < n;i++){
		ans = max(ans, c[i]);
	}
	printf("%d", ans);
}