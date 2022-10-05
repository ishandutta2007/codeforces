#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 300005;

int n, k;
ll a[N];

int main(){
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++) scanf("%lld", a + i);
	for(int i = n - 1; i >= 0; i--) a[i] += a[i + 1];
	sort(a + 1, a + n); reverse(a + 1, a + n);
	ll r = 0;
	for(int i = 0; i < k; i++) r += a[i];
	printf("%lld\n", r);
}