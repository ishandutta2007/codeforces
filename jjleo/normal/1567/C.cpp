#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int t, n;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		ll f[2][2] = {{1, 0}, {0, 0}};
		while(n){
			int val = n % 10;
			ll g[2][2];
			g[0][0] = f[0][0] * (val + 1) + f[0][1] * val;
			g[0][1] = f[1][0] * (val + 1) + f[1][1] * val;
			g[1][0] = f[0][0] * (18 - val - 9) + f[0][1] * (18 - val - 8);
			g[1][1] = f[1][0] * (18 - val - 9) + f[1][1] * (18 - val - 8);
			memcpy(f, g, sizeof(g));
			n /= 10;
		}
		printf("%lld\n", f[0][0] - 2);
	}
}