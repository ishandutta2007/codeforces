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

#include <bitset>
const int N = 155;
const int S = 100500;
bitset<N * N> ed, st, T, L, R, D, U;
char s[S];

int m, n, len;
int num(int x, int y) {
	return (x - 1) * m + y;
}

int main() {
	read(n), read(m), read(len);
	for (int i = 1;i <= n; i++) {	
		scanf ("%s", s + 1);
		for (int j = 1;j <= m; j++) {
			if (s[j] == 'E') ed[num(i, j)] = T[num(i, j)] = 1;
			else if (s[j] == '#') {
				if (i != 1) D[num(i - 1, j)] = 1;
				if (i != n) U[num(i + 1, j)] = 1;
				if (j != 1) R[num(i, j - 1)] = 1;
				if (j != m) L[num(i, j + 1)] = 1;
			}
			else T[num(i, j)] = 1;
		}
	}
	scanf ("%s", s + 1); st = T;
	if (T == ed) return puts("0"), 0;
	for (int i = 1;i <= len; i++) {
		if (s[i] == 'U') T = (T >> m & st) | (T & U);
		else if (s[i] == 'D') T = (T << m & st) | (T & D);
		else if (s[i] == 'L') T = (T >> 1 & st) | (T & L);
		else if (s[i] == 'R') T = (T << 1 & st) | (T & R);
		if (ed == T) return write(i), 0;
	}
	write(-1);
	return 0;
}