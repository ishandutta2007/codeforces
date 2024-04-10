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

const int N = 2005;
#include <bitset>
int bit[N][2], cnt;
bitset<N> A[N];
char op[55];
#define ls x << 1
#define rs ls | 1
int val[N], m, n;
void turn12() {
	int k; read(k);
	for (int i = 1, x;i <= k; ++i) 
		read(x), swap(bit[ls], bit[rs]);
}

void turn23() {
	int k; read(k);
	for (int i = 1, x;i <= k; ++i) 
		read(x), bit[ls][1] ^= bit[rs][1], bit[ls][0] ^= bit[rs][0];
}

void turn13() {
	int k; read(k);
	for (int i = 1, x;i <= k; ++i) 
		read(x), bit[rs][0] ^= bit[ls][0], bit[rs][1] ^= bit[ls][1];
}

//RBY
void func() {
	int k; read(k), ++cnt;
	for (int i = 1, x;i <= k; ++i) {
		read(x);
		A[cnt][ls] = bit[ls][0], A[cnt][rs] = bit[ls][1];
		A[cnt + 1][ls] = bit[rs][0], A[cnt + 1][rs] = bit[rs][1];
	}
	scanf ("%s", op);
	if (op[0] == 'W') return ++cnt, void();
	A[cnt][2 * n + 2] = op[0] != 'B';
	A[++cnt][2 * n + 2] = op[0] != 'R';
}

int usd[N];
void Gauss() {
	for (int i = 1;i <= 2 * n + 1; ++i) {
		for (int j = 1;j <= cnt; ++j) 
			if (!usd[j] && A[j][i]) { swap(A[i], A[j]); break; }
		if (!A[i][i]) continue;
		usd[i] = 1;
		for (int k = 1;k <= max(cnt, 2 * n + 1); ++k)
			if (A[k][i] && i != k) A[k] ^= A[i];
	}
	for (int i = 1;i <= max(2 * n + 1, cnt); ++i) {
		int t = A[i]._Find_first();
		if (t > 2 * n + 2) continue;
		if (t == 2 * n + 2) { puts("NO"); exit(0); }
		val[t] = A[i][2 * n + 2];
	}
}

int main() {
	read(n), read(m);
	for (int i = 2;i <= 2 * n + 1; ++i) bit[i][i & 1] = 1;
	for (int i = 1;i <= m; ++i) {
		scanf ("%s", op);
		if (op[0] == 'm') func();
		else if (op[0] == 'R' && op[1] == 'B') turn12();
		else if (op[0] == 'R' && op[1] == 'Y') turn13();
		else turn23();
	}
	Gauss();
	puts("YES");
	for (int i = 1;i <= n; ++i) {
		int t = val[i << 1] | val[i << 1 | 1] << 1;
		putchar(".RBY"[t]); 
	}
	return 0;
}

/*

5 8
mix 5 1 3 2 4 5 Y
RB 2 4 5
mix 3 1 4 3 B
RB 3 1 2 3
mix 4 2 5 3 4 W
RY 3 4 2 1
mix 3 1 2 3 B
mix 1 4 B

5 8
Y.YRB
mix 5 1 3 2 4 5 Y
RB 2 4 5
mix 3 1 4 3 B
RB 3 1 2 3
mix 4 2 5 3 4 W
RY 3 4 2 1
mix 3 1 2 3 B
mix 1 4 B

*/