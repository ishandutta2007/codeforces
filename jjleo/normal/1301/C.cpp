#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n, m;
long long ans;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		if(!m){
			puts("0");
			continue;
		}
		ans = 1ll * n * (n + 1) / 2;
		int x = (n - m) / (m + 1), y = (n - m) % (m + 1);
		ans -= 1ll * (x + 1) * (x + 2) / 2 * y + 1ll * x * (x + 1) / 2 * (m + 1 - y);
		printf("%lld\n", ans);
	}
}