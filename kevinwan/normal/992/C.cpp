#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
ll p(ll a, ll b) {
	ll ans = 1,cur=a;
	while (b) {
		if (b & 1)ans = ans * cur%mod;
		cur = cur * cur%mod;
		b >>= 1;
	}
	return ans;
}
int main() {
	ll n, k;
	scanf("%lld%lld", &n, &k);
	if(n==0){
	    printf("0");return 0;
	}
	n %= mod;
	n = n * 2 - 1;
	n %= mod;
	n = n * p(2, k)%mod;
	n+=mod+1;
	n %= mod;
	printf("%lld", n);
	getchar(); getchar();
}