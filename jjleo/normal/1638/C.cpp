#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;
int a[maxn], x;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		int mn = n + 1, mx = 0, ans = 0;
		for(int i = 1;i <= n;i++){
			scanf("%d", &x), mn = min(mn, x), mx = max(mx, x);
			if(mn == 1 && mx == i) ans++;
		}
		printf("%d\n", ans);
	}
}