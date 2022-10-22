#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m;
ll num(int a, int b) {
	ll ret = 0;
	ll i, j;
	for (i = 1; i <= a; i++)for (j = 1; j <= b; j++)if ((i*i + j * j) % m == 0)ret++;
	return ret;
}
int main() {
	cin >> n >> m;
	printf("%lld", num(m, m)*(n / m)*(n / m) + num(n%m, n%m) + 2 * (n / m)*num(n%m, m));
	getchar(); getchar();
}