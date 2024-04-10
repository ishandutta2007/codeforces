#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;
int a[maxn], b[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d%d", &a[i], &b[i]);
		if(n & 1){
			puts("1");
			continue;
		}
		sort(a + 1, a + 1 + n), sort(b + 1, b + 1 + n);
		printf("%lld\n", 1ll * (a[n / 2 + 1] - a[n / 2] + 1) * (b[n / 2 + 1] - b[n / 2] + 1));
	}
}