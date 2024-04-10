#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int read(void) {
	int x = 0;
	char c = getchar();
	while (!isdigit(c)) c = getchar();
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + c - '0';
		c = getchar();
	}
	return x;
}
const int N = 200050;
#define ll long long
const ll INF = 0x7ffffffffffff;
ll f[N][2], T, n, a, b;
char s[N];
int main() {
	T = read();
	while (T--) {
		n = read(), a = read(), b = read();
		scanf ("%s", s + 1);
		ll ans = n * a + b * (n + 1);
		f[0][0] = 0;
		f[0][1] = INF;
		for (int i = 1;i <= n; i++) {
			if (s[i] == '0' && s[i+1] != '1') {
				f[i][1] = min(f[i-1][1], f[i-1][0] + a) + b;
				f[i][0] = min(f[i-1][1] + a, f[i-1][0]);
			}
			else {
				f[i][0] = INF, f[i][1] = min(f[i-1][1], f[i-1][0] + a) + b;
			}
		}/*
		for (int i = 1;i <= n; i++) {
			if (f[i][0] == INF) cout << -1 << ' ';
			else cout << f[i][0] << ' ';
			cout << f[i][1] << endl;
		}*/
		cout << f[n][0] + ans << endl;
	}
	return 0;
}