#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[200001];
set<int> s;
int main() {
	int n,i,x;
	ll ans = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)scanf("%d", &x),a[x]++,s.insert(x);
	for (i = 1; i <= 200000; i++)a[i] += a[i - 1];
	for (int x : s) {
		ll temp = 0;
		for (i = 0; i*x <= 200000; i++)temp += (1LL * i*x)*(a[min((i + 1)*x - 1, 200000)] - a[max(i*x - 1, 0)]);
		ans = max(ans, temp);
	}
	printf("%lld", ans);
	getchar(); getchar();
}