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

const int N = 2005;
char s[N][N];
int L[N][N], R[N][N], LD[N][N], RD[N][N], m, n;
int h[N][N];
void work(int (*A)[N]) {
	for (int i = 1;i <= n; i++) {
		for (int j = 1;j <= m; j++) {
			h[i][j] = 1 + (s[i][j] == s[i-1][j] ? h[i-1][j] : 0);
			A[i][j] = min(h[i][j], A[i][j-1] + 1);
			if (s[i][j] != s[i][j-1]) A[i][j] = 1;
		}
	}
}

void solve(int (*A)[N], int (*B)[N]) {
	work(A);
	for (int i = 1;i <= n; i++) reverse(s[i] + 1, s[i] + m + 1);
	work(B);
	for (int i = 1;i <= n; i++) 
		reverse(s[i] + 1, s[i] + m + 1), reverse(B[i] + 1, B[i] + m + 1);
}



int main() {
	read(n), read(m);
	for (int i = 1;i <= n; i++) scanf ("%s", s[i] + 1);
	solve(L, R);
	for (int i = 1;i + i <= n; i++) swap(s[i], s[n-i+1]);
	solve(LD, RD);
	for (int i = 1;i + i <= n; i++) swap(LD[i], LD[n-i+1]), swap(RD[i], RD[n-i+1]);
	ll ans = 0;
	for (int i = 1;i <= n; i++) {
		for (int j = 1;j <= m; j++) {
			int t = min(min(L[i][j], R[i][j]), min(LD[i][j], RD[i][j])); 
			ans += t;
//			write(t, ' ');
		}
//		puts("");
	}
	write(ans);
	return 0;
}

/*

4 6
aaaaaa
aaaaaa
aaaaaa
aaaaaa

*/