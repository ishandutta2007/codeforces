#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t, n, x;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &x);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		int ans = 0;
		int mn = 1e9, mx = -1e9;
		for(int i = 1;i <= n;i++){
			mn = min(mn, a[i]);
			mx = max(mx, a[i]);
			if(mx - mn > x * 2){
				ans++;
				mn = mx = a[i];
			}
		}
		printf("%d\n", ans);
	}
}