
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

const int N = 5005;
int dx[] = {0, -1, 1, 0, 0};
int dy[] = {0, 0, 0, -1, 1};
int val[200], sx, sy, n;
char s[N];

bool solve(void) {
	int tx = 0, ty = 0;
	for (int i = 1;i <= n; ++i) {
		int c = val[s[i]], x = tx + dx[c], y = ty + dy[c];
		if (sx == x && sy == y) continue;
		tx = x, ty = y;
	}
	return tx == 0 && ty == 0;
}

int T;
int main() {
	val['L'] = 1, val['R'] = 2, val['D'] = 3, val['U'] = 4;
	for (read(T); T; T--) {
		scanf ("%s", s + 1), n = strlen(s + 1);
		sx = sy = 1e8; if (solve()) { write(sx, ' '), write(sy); continue; }
		sx = sy = 0; int fl = 0;
		for (int i = 1;i <= n; ++i) {
			int c = val[s[i]], x = sx + dx[c], y = sy + dy[c];
			sx = x, sy = y;
			if ((sx || sy) && solve())  { write(sx, ' '), write(sy); fl = 1; break; }
		}
		if (!fl) write(0, ' '), write(0);
	}
	return 0;
}