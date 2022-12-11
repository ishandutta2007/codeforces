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

const int N = 2005;
int q[N], p[N], f[N], T, n;
int main() {
	for (read(T); T; T--) {
		read(n); n *= 2, memset(f, 0, sizeof(f)); f[0] = 1;
		for (int i = 1;i <= n; i++) read(p[i]);
		int st = 1, tp = 0;
		while (st <= n) {
			int v = 0, nw = st;
			for (nw = st;nw <= n; nw++) 
				if (p[nw] > p[st]) break;
				else v++;
			st = nw, q[++tp] = v;
		}
		for (int i = 1;i <= tp; i++) 
			for (int j = n;j >= q[i]; j--)
				f[j] |= f[j-q[i]];
		puts(f[n/2] ? "YES" : "NO");	
	}
	return 0;
}

/*

5
2
3 1 2 4
4
3 2 6 1 5 7 8 4
3
1 2 3 4 5 6
4
6 1 3 7 4 5 8 2
6
4 3 2 5 1 11 9 12 8 6 10 7


*/