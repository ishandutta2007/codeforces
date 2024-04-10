
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

const int N = 1050;
int T, m, n;
int p[N][N], g[N][N];
const int M = 105800;
char s[M];
int main() {
	for (read(T); T; T--) {
		read(n), read(m);
		for (int i = 0; i < n; i++)
			for (int j = 0;j < n; j++)
				read(p[i][j]), --p[i][j];
		int A = 0, B = 0, C = 0;
		scanf ("%s", s + 1);
		int t1 = 1, t2 = 2, t3 = 3;
		for (int i = 1;i <= m; i++) {
			if (s[i] == 'R') ++B;
			else if (s[i] == 'L') --B;
			else if (s[i] == 'D') ++A;
			else if (s[i] == 'U') --A;
			else if (s[i] == 'I') swap(t2, t3), swap(B, C);
			else if (s[i] == 'C') swap(t1, t3), swap(A, C);
		}
		auto mod = [&](int x) { return ((x % n) + n) % n; };
		for (int i = 0;i < n; i++)
			for (int j = 0;j < n; j++) {
				int tt1 = mod((t1 == 1 ? i : t1 == 2 ? j : p[i][j]) + A);
				int tt2 = mod((t2 == 1 ? i : t2 == 2 ? j : p[i][j]) + B);
				int tt3 = mod((t3 == 1 ? i : t3 == 2 ? j : p[i][j]) + C);
				g[tt1][tt2] = tt3;
			}
		for (int i = 0;i < n; i++, puts(""))
			for (int j = 0;j < n; j++)
				write(g[i][j] + 1, ' ');
	}
	return 0;
}