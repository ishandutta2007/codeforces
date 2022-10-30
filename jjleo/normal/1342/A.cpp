#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, x, y, a, b;

typedef long long ll;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d%d", &x, &y, &a, &b);
		printf("%lld\n", min(1ll * (abs(x) + abs(y)) * a, 1ll * abs(x - y) * a + 1ll * min(abs(x), abs(y)) * b));
	}
}