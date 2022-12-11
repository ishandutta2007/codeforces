#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
const int N = 100050;
ll f[N], ans[N];
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

ll n, a[N];
ll siz[N];

int find(int x) {
	if (x == f[x]) return x;
	return f[x] = find(f[x]);
}

int v[N];

int main() {
	n = read();
	for (int i = 1;i <= n; i++) 
	a[i] = read(), f[i] = i;
	for (int i = 1;i <= n; i++) ans[i] = read();
	for (int i = n;i >= 1; i--) {
		ll tmp = ans[i];
		ans[i] = max(ans[i+1], a[tmp]);
		v[tmp] = 1;
		siz[tmp] = a[tmp];
		if (v[tmp+1]) {
			f[tmp] = find(tmp + 1);
			siz[f[tmp+1]] += a[tmp];
			ans[i] = max(ans[i], siz[f[tmp+1]]); 
		}
		if (v[tmp-1]) {
			int t = find(tmp - 1);
			siz[t] += siz[f[tmp]];
			f[f[tmp]] = t;
			ans[i] = max(ans[i], siz[f[tmp-1]]);
		}
	}
	for (int i = 1;i <= n; i++) printf ("%lld\n", ans[i+1]);
	return 0;
}