#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n, q, k;
int a[maxn];
long long b[maxn];
int l, r;

int main(){
	scanf("%d%d%d", &n, &q, &k);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	for(int i = 2;i < n;i++){
		b[i] = b[i - 1] + a[i + 1] - a[i - 1] - 2;
	}
	while(q--){
		scanf("%d%d", &l, &r);
		if(l == r){
			printf("%d\n", k - 1);
			continue;
		}
		long long ans = 0;
		ans += a[l + 1] - 2 + (k - a[r - 1] - 1);
		if(l + 1 <= r - 1) ans += b[r - 1] - b[l];
		printf("%lld\n", ans);
	}
	
}