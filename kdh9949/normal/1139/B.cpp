#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 200005;

int n;
ll a[N], r;

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%lld", a + i);
	r += a[n];
	for(int i = n - 1; i >= 1; i--){
		a[i] = min(a[i], a[i + 1] - 1);
		if(!a[i]) break;
		r += a[i];
	}
	printf("%lld\n", r);
}