#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) {
	while (b)a %= b, a ^= b ^= a ^= b;
	return a;
}
int main() {
	ll a, b, x, y,g;
	cin >> a >> b >> x >> y;
	g = gcd(x, y);
	x /= g, y /= g;
	printf("%lld", min(a / x, b / y));
	getchar(); getchar();
}