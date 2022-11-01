#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int n;
int a[maxn], b[maxn];

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]), b[a[i]] = i;
	int ans = 0, x = 0, r = 0;
	while(x < n){
		int mx = 0;
		while(x < r) mx = max(mx, b[a[++x]]);
		if(mx > r){
			ans += mx - r - 1;
			r = mx;
			continue;
		}
		while(x < n){
			x++;
			if(b[a[x]] == x) continue;
			ans += b[a[x]] - x + 1 - 2, r = b[a[x]];
			break;
		}
	}
	printf("%d", ans);
}