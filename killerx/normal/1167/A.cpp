#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read() {
	int  x = 0, f = 1, c = getchar();
	for (;!isdigit(c); c = getchar()) if (c == '-') f ^= 1;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}
inline void write(int x) {
	if (!x) {putchar('0'); return;}
	if (x < 0) {putchar('-'); x = -x;}
	int stk[20], tp = 0;
	for (; x; x /= 10) stk[tp ++] = x % 10;
	for (; tp; putchar(stk[-- tp] + '0')) ;
}
int main() {
	int t = read();
	for (; t --; ) {
		int n = read();
		char s[105]; scanf("%s", s);
		bool ok = 0;
		for (int i = 0; i < n; ++ i) if (s[i] == '8') {
			ok |= i <= n - 11;
		}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}