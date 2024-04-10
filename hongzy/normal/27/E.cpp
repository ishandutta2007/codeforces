#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long LL;

int n, p[14] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43};
int lim[14] = {60, 38, 26, 21, 17, 17, 17, 17, 17, 17, 17, 17, 17};
LL ans = 1e18;
int a[15];

LL Pow(LL a, LL b) {
	LL ans = 1;
	for(; b; b >>= 1) {
		if(b & 1) {
			if(a > ::ans) return -11;
			ans = ans * a;
			if(ans > ::ans) return -11;
		}
		if(a > 1e9 && (b / 2)) return -11;
		a = a * a;
		if(a > :: ans) return -11;
	}
	return ans;
}

bool Boom(LL a, LL b) {
	int c1 = 0, c2 = 0;
//	cout << a << ' ' << b;
	for(; a; a /= 10) ++ c1;
	for(; b; b /= 10) ++ c2;
//	cout << "<>\nc1+c2 " << c1 + c2 << endl;
	return c1 + c2 > 19;
}

void check() {
	LL now = 1, k;
	for(int i=1; i<=14; i++) {
		k = Pow(p[i-1], a[i]);
		if(k == -11) return ;
		if(Boom(now, k)) return ;
		now *= k;
		if(now > ans) return ;
	}
	ans = now;
}

void dfs(int x, int l, int c) {
	if(x == 0) {
		if(c == n) check();
		return ;
	}
	LL now = 1;
	for(int i=0; i<=lim[x-1] && now <= ans; i++) {
		a[x] = i;
		if(c * (i + 1) > n) break;
		dfs(x-1, l, c * (i + 1));
		now *= p[x-1];
	}
}

int main() {
	scanf("%d", &n);
	dfs(14, n, 1);
	printf("%lld\n", ans);
	return 0;
}