#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		sort(a + 1, a + 1 + n);
		printf("%lld\n", 1ll * a[n] + a[n - 1] - a[1] - a[2]);
	}
}