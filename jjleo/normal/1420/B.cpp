#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;
int a[maxn];
int cnt[50];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		memset(cnt, 0, sizeof(cnt));
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]), cnt[__builtin_clz(a[i])]++;
		long long ans = 0;
		for(int i = 0;i <= 40;i++) ans += 1ll * cnt[i] * (cnt[i] - 1) / 2;
		printf("%lld\n", ans);
	}
}