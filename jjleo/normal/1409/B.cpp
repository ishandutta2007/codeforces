#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n, a, b, x, y;

inline long long cal(int n, int a, int b, int x, int y){
	int cnt = min(n, a - x);
	a -= cnt;
	b -= min(b - y, n - cnt);
	return 1ll * a * b;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d%d%d", &a, &b, &x, &y, &n);
		printf("%lld\n", min(cal(n, a, b, x, y), cal(n, b, a, y, x)));
	}
}