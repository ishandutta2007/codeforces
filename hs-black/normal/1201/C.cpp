#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int N = 200050;
int a[N], n;
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

ll k;

int main() {
	n = read(), k = read();
	for (int i = 1;i <= n; i++) a[i] = read();
	sort(a + 1, a + n + 1);
	ll t = n / 2 + 1;
	ll ans = a[t], cnt = 0;
	for (int i = t;i <= n; i++) {
		ll ned = a[i] - ans;
		ned *= cnt;
		if (ned > k)
			break;
		k -= ned;
		ans = a[i];
		cnt++;
	}
	ans += k / cnt;
	cout << ans << endl;
	return 0;
}