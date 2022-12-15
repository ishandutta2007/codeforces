/*
    ___                         ______      __                  __
   /   |____  __  ___________ _/ ____/___ _/ /___  ____  ______/ /____
  / /| /_  / / / / / ___/ __ `/ /   / __ `/ __/ / / / / / / __  / ___/
 / ___ |/ /_/ /_/ (__  ) /_/ / /___/ /_/ / /_/ /_/ / /_/ / /_/ (__  )
/_/  |_/___/\__,_/____/\__,_/\____/\__,_/\__/\__, /\__, /\__,_/____/
                                            /____//____/

 
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

int T, n;
bool check(int *A) {
	int s = 0;
	for (int i = 1;i <= n && s >= 0; ++i) 
		s += A[i] ? 1 : -1;
	return s == 0;
}

const int N = 200050;
char s[N]; int A[N], B[N];
#define NO puts("NO")
void out(int *A) {
	for (int i = 1;i <= n; ++i)
		putchar(A[i] ? '(' : ')');
	puts("");
}
int main() {
	for (read(T); T; T--) {
		read(n), scanf ("%s", s + 1);
		int k0 = 0;
		for (int i = 1;i <= n; ++i) k0 += s[i] == '0';
		if (k0 & 1) { NO; continue; }
		int k1 = (n - k0) >> 1;
		for (int i = 1;i <= n; ++i) {
			if (s[i] == '0') A[i] = k0 & 1, B[i] = ~k0 & 1, --k0;
			else A[i] = B[i] = k1 ? (--k1, 1) : 0;
		}
		if (!check(A) || !check(B)) NO;
		else puts("YES"), out(A), out(B); 
	}
	return 0;
}