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
inline void write(F x, char ed = '\n')
{
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

const int N = 50005;
int T, n, a[N], b[N];
int main() {
	for (read(T); T; T--) {
		read(n); int A = 1e9, B = 1e9;
		ll ans = 0;
		for (int i = 1;i <= n; i++) read(a[i]), Mn(A, a[i]);
		for (int i = 1;i <= n; i++) read(b[i]), Mn(B, b[i]);
		for (int i = 1;i <= n; i++) {
			int ka = a[i] - A, kb = b[i] - B;
			int t = min(ka, kb);
			ans += ka + kb - t;
		}
		write(ans);
	}
	return 0;
}