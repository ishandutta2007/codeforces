#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

const int p = 1e9 + 7;

int t, n, a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		int sum = (1 << 30) - 1;
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]), sum &= a[i];
		int cnt = 0;
		for(int i = 1;i <= n;i++) cnt += a[i] == sum;
		int ans = 1ll * cnt * (cnt - 1) % p;
		for(int i = 1;i <= n - 2;i++) ans = 1ll * ans * i % p;
		printf("%d\n", ans);
	}
}