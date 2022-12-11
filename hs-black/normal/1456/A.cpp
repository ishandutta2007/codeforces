
/*
 
| _ _|
 ` _x 
  /  |
 /   ?
| |||
| (__)_)

 */

#include <queue>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MP make_pair
#define ll long long
#define fi first
#define se second
using namespace std;

template <typename T>
void read(T &x) {
    x = 0; bool f = 0;
    char c = getchar();
    for (;!isdigit(c);c=getchar()) if (c=='-') f=1;
    for (;isdigit(c);c=getchar()) x=x*10+(c^48);
    if (f) x=-x;
}

template<typename F>
inline void write(F x, char ed = '\n') {
	static short st[30];short tp=0;
	if(x<0) putchar('-'),x=-x;
	do st[++tp]=x%10,x/=10; while(x);
	while(tp) putchar('0'|st[tp--]);
	putchar(ed);
}

template <typename T>
inline void Mx(T &x, T y) { x < y && (x = y); }

template <typename T>
inline void Mn(T &x, T y) { x > y && (x = y); }

const int N = 200500;
int n, p, k, T, cnt[N], x, y;
char s[N];
int main() {
	for (read(T); T; T--) {
		read(n), read(p), read(k);
		scanf ("%s", s + 1);
		for (int i = 1;i <= n; i++) 
			if (i >= p) cnt[i % k] += s[i] ^ '0';
		read(x), read(y);
		int ans = 1e9;
		for (int i = p;i <= n; i++) {
			Mn(ans, (1 + (n - i) / k - cnt[i % k]) * x + (i - p) * y);
			cnt[i % k] -= s[i] ^ '0';
		}
		write(ans);
	}
	return 0;
}