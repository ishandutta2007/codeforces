#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, k;
int a[maxn], b[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]), b[i] = a[i];
		sort(b + 1, b + 1 + n);
		for(int i = 1;i <= n;i++) a[i] = lower_bound(b + 1, b + 1 + n, a[i]) - b;
		int cnt = 1;
		for(int i = 2;i <= n;i++) cnt += a[i] != a[i - 1] + 1;
		puts(cnt <= k ? "Yes" : "No");
	}
}