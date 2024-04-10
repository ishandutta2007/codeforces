#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

typedef long long ll;

int t, a, b, q;
ll l, r;
int sum[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &a, &b, &q);
		int lcm = a * b / __gcd(a, b);
		for(int i = 1;i <= lcm;i++) sum[i] = sum[i - 1] + (i % a % b != i % b % a);
		
		while(q--){
			scanf("%lld%lld", &l, &r);
			if((l - 1) / lcm == r / lcm) printf("%d ", sum[r % lcm] - sum[(l - 1) % lcm]);
			else printf("%lld ", 1ll * sum[r % lcm] + 1ll * sum[lcm] - 1ll * sum[(l - 1) % lcm] + (r / lcm - (l - 1) / lcm - 1) * sum[lcm]);
		}
		puts("");
	}
}