#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

typedef long long ll;

int n, m;
ll a[maxn], b[maxn];

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++) scanf("%lld", &a[i]);
	for(int i = 1;i <= m;i++) scanf("%lld", &b[i]);
	ll x = a[2] - a[1];
	for(int i = 3;i <= n;i++) x = __gcd(x, a[i] - a[i - 1]);
	for(int i = 1;i <= m;i++){
		if(n == 1) printf("%lld ", a[1] + b[i]);
		else printf("%lld ", abs(__gcd(a[1] + b[i], x)));
	}
}