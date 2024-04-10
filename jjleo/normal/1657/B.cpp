#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int t, n, b, x, y;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d%d", &n, &b, &x, &y);
		int now = 0;
		ll ans = 0;
		for(int i = 1;i <= n;i++){
			if(now + x > b) now -= y;
			else now += x;
			ans += now;
		}
		printf("%lld\n", ans);
	}
}