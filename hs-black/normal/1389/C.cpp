
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

const int N = 200500;
int cnt[20], p[10][10], T, n;
char s[N];
int main() {
	for (read(T); T; T--) {
		scanf ("%s", s + 1), n = strlen(s + 1);
		memset(cnt, 0, sizeof(cnt));
		memset(p, 0, sizeof(p));
		for (int i = 1;i <= n; i++) {
			cnt[s[i]^'0']++;
			for (int j = 0;j <= 9; j++)
				Mx(p[j][s[i]^'0'], p[s[i]^'0'][j] + 1);
		}
		int mx = 0;
		for (int i = 0;i <= 9; i++) {
			Mx(mx, cnt[i]);
			for (int j = 0;j <= 9; j++)
				Mx(mx, p[i][j] - (p[i][j] & 1));
		}
		write(n - mx);
	}
	return 0;
}