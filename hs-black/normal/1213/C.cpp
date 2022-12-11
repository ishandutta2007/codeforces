#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define ll long long
ll read(void) {
	ll x = 0;
	char c = getchar();
	while (!isdigit(c)) c = getchar();
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + c - '0';
		c = getchar();
	}
	return x;
}
int q;
ll n, m;
int main() {
	q = read();
	while(q--) {
		n = read(), m = read();
		ll cnt = 0, ans = 0;
		if (m > n) {
			printf ("0\n");
			continue;
		}
		for (int i = 1;i <= 9; i++) cnt += m * i % 10;
		ans += n / (m * 10) * cnt;
		n %= (m * 10);
		for (ll i = m;i <= n; i += m) ans += i % 10;
		cout << ans << endl;
	}
	return 0;
}