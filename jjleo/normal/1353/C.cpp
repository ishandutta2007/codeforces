#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int t;
int n;
ll ans;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		n = (n - 1) >> 1;
		ans = 0;
		for(ll i = 1;i <= n;i++){
			ans += ((2 * i + 1) * (2 * i + 1) - (2 * i - 1) * (2 * i - 1)) * i;
		}
		printf("%lld\n", ans);
	}
}