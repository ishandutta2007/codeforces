#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n, x;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &x);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		sort(a + 1, a + 1 + n);
		int ans = 0, cnt = 0;
		for(int i = n;i;i--){
			cnt++;
			if(1ll * a[i] * cnt >= x) cnt = 0, ans++;
		}
		printf("%d\n", ans);
	}
}