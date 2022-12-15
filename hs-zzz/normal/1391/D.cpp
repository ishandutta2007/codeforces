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

const int N = 2005000;
int p[N], m, n;
int sum[2][10];

int ch[][2] = {
	{0, 7},
	{1, 6},
	{3, 4},
	{2, 5}
};

int siz[] = {0, 1, 1, 2, 1, 2, 2, 3};

int cc[][2] = {
	{0, 3},
	{1, 2}
};
void work2() {
	for (int i = 1;i <= m; i++) 
		for (int j = 0;j < 2; j++)
			sum[i & 1][j] += min(siz[p[i] ^ cc[j][0]], siz[p[i] ^ cc[j][1]]);
	write(min(sum[0][0] + sum[1][1], sum[0][1] + sum[1][0]));
}

void work3(void) {
	int ans = n * m;
	for (int i = 1;i <= m; i++) 
		for (int j = 0;j < 4; j++) 
			sum[i & 1][j] += min(siz[p[i] ^ ch[j][0]], siz[p[i] ^ ch[j][1]]);
	for (int j = 0;j < 4; j++)
		Mn(ans, sum[0][j] + sum[1][3 ^ j]);
	write(ans);
}

char s[N];
int main() {
	read(n), read(m);
	if (n >= 4 && m >= 4) return puts("-1"), 0;
	if (n == 1 || m == 1) return puts("0"), 0;
	for (int i = 1;i <= n; i++) {
		scanf ("%s", s + 1);
		for (int j = 1;j <= m; j++) 
			p[j] = p[j] * 2 + (s[j] - '0');
	}
	if (n == 2) work2();
	else work3();
	return 0;
}

/*

2 4
1010
1010

*/