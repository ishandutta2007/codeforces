#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int t;
ll n, x;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%lld", &n);
		x = 1;
		int ans = 0;
		while(1){
			if(n - x * (x + 1) / 2 < 0) break;
			ans++, n -= x * (x + 1) / 2;
			x = x * 2 + 1;
		}
		printf("%d\n", ans);
	}
}