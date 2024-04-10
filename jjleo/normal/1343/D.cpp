#include <bits/stdc++.h>
#define maxn 400086

using namespace std;

int t;
int n, k;
int a[maxn], b[maxn], bk[maxn];
int ans;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		for(int i = 1;i <= k * 2;i++) b[i] = bk[i] = 0;
		for(int i = 1;i <= n / 2;i++) ++b[a[i] + a[n + 1 - i]], ++bk[min(a[i], a[n + 1 - i]) + 1], --bk[max(a[i], a[n + 1 - i]) + k + 1];
		for(int i = 1;i <= k * 2;i++) bk[i] += bk[i - 1];
		//for(int i = 1;i <= k * 2;i++) printf("%d ", b[i]);puts("--");
		//for(int i = 1;i <= k * 2;i++) printf("%d ", bk[i]);puts("--");
		ans = n / 2;
		for(int i = 1;i <= k * 2;i++) ans = min(ans, bk[i] - b[i] + 2 * (n / 2 - bk[i]));
		printf("%d\n", ans);
	}
}