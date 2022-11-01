#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t, n;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		sort(a + 1, a + 1 + n);
		int ans = 0;
		for(int i = 1;i + 2 <= n;i++) ans = max(ans, a[i + 1] - a[i] + a[n] - a[i]);
		reverse(a + 1, a + 1 + n);
		for(int i = 1;i + 2 <= n;i++) ans = max(ans, -(a[i + 1] - a[i] + a[n] - a[i]));
		printf("%d\n", ans);
	}
}