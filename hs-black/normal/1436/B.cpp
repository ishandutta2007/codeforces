
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

const int N = 2050;
int T, n;
int prime[N], e[N], tot;
void prework(void) {
	const int lim = 1000;
	for (int i = 2;i <= lim; i++) {
		if (!e[i]) prime[++tot] = e[i] = i;
		for (int j = 1;j <= tot && prime[j] * i <= lim; j++) {
			e[prime[j] * i] = prime[j]; if (prime[j] == i) break;
		}
	}
}
int main() {
	prework(); int pp = 0;
	for (read(T); T; T--) {
		read(n);
		for (int j = 1;j <= tot; j++)
			if (prime[j] > n && e[prime[j] - n + 1] != prime[j] - n + 1) {
				pp = prime[j]; break;
			}
		pp -= n - 1;
		for (int i = 1;i <= n; i++, puts("")) 
			for (int j = 1;j <= n; j++)
				write(i == j ? pp : 1, ' ');
	}
	return 0;
}