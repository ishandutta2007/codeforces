#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

typedef long long ll;

int t, n;
ll a[maxn], k;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%lld", &n, &k);
		for(int i = 1;i <= n;i++) scanf("%lld", &a[i]);
		sort(a + 1, a + 1 + n);
		ll x = a[2] - a[1];
		for(int i = 3;i <= n;i++) x = __gcd(x, a[i] - a[i - 1]);
		bool tag = false;
		for(int i = 1;i <= n && !tag;i++) if((k - a[i]) % x == 0) tag = true;
		puts(tag ? "YES" : "NO");
	}
}