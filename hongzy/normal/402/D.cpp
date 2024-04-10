#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;

const int N = 5010;

int n, m, a[N];
map<int, bool> ba;

int calc(int x) {
	int res = 0;
	for(int i = 2; i * i <= x; i ++) {
		if(x % i == 0) {
			int c = ba[i] ? -1 : 1;
			while(x % i == 0) {
				x /= i; res += c;
			}
		}
	}
	if(x > 1) res += ba[x] ? -1 : 1;
	return res;
}

int main() {
	scanf("%d%d", &n, &m); //sieve(M - 1);
	for(int i = 1; i <= n; i ++) {
		scanf("%d", a + i);
	}
	for(int i = 1; i <= m; i ++) {
		int x; scanf("%d", &x); ba[x] = 1;
	}
	for(int i = n; i >= 1; i --) {
		int g = 0;
		for(int j = i; j >= 1; j --) g = __gcd(g, a[j]);
		if(calc(g) < 0) {
			for(int j = i; j >= 1; j --) {
				a[j] /= g;
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i ++) ans += calc(a[i]);
	printf("%d\n", ans);
	return 0;
}