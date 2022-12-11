#include <algorithm>
#include <cstdio>
using namespace std;
const int m = (1 << 30) - 1;
const int N = 4e6 + 5;
int p[N], mu[N], f[N], c;
bool tag[N];
void sieve(int n) {
	mu[1] = 1;
	for(int i = 2; i <= n; i ++) {
		if(!tag[i]) { p[++ c] = i; mu[i] = -1; }
		for(int j = 1; j <= c && i * p[j] <= n; j ++) {
			tag[i * p[j]] = 1;
			if(i % p[j] == 0) break ;
			mu[i * p[j]] = - mu[i];
		}
	}
}
int main() {
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	if(a > b) swap(a, b);
	if(a > c) swap(a, c);
	if(b > c) swap(b, c);
	int ans = 0; sieve(a * b);
	for(int i = 1; i <= c; i ++) {
		int g = 0;
		for(int j = i; j <= c; j += i) {
			g += c / j;
		}
		for(int j = i; j <= a * b; j += i) {
			(f[j] += mu[i] * g) &= m;
		}
	}
	for(int i = 1; i <= a; i ++) {
		for(int j = 1; j <= b; j ++) {
			if(__gcd(i, j) == 1) {
				(ans += (1ll * (a / i) * (b / j) * f[i * j]) & m) &= m;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}