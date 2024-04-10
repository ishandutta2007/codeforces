#include<iostream>
#include<cstring>
#include<cstdio>
#include<deque>
#define ll long long
using namespace std;
const int N = 100050;
deque<ll> q;
ll ans[N][3];
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
ll n, m;
ll a[N];
int main() {
	n = read(), m = read();
	for (int i = 1;i <= n; i++) {
		ll x = read();
		q.push_back(x);
	}
	for (int i = 1;i < n; i++) {
		ll x = q.front(); q.pop_front();
		ll y = q.front(); q.pop_front();
		ans[i][1] = x, ans[i][2] = y;
		if (x < y) swap(x, y);
		q.push_back(y);
		q.push_front(x);
	}
	for (int i = 1;i <= n; i++) {
		a[i] = q.front(); q.pop_front();
	}
	for (int i = 1;i <= m; i++) {
		ll ti = read();
		if (ti <= n - 1) printf ("%lld %lld\n", ans[ti][1], ans[ti][2]);
		else {
			ti--;
			ti %= n - 1;
			printf ("%lld %lld\n", a[1], a[2 + ti]);
		}
	}
	return 0;
}
/*
5 200
1 2 3 4 5

*/