
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

const int N = 200050;
int f[N], len[N], tp, T, n; char s[N];
int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
int main() {
//	freopen ("hs.in","r",stdin);
	for (read(T); T; T--) {
		read(n), scanf ("%s", s + 1);
		tp = 0;
		for (int l = 1, r = 1;l <= n; l = r + 1, r = l) {
			while (r <= n && s[r+1] == s[l]) r++;
			len[++tp] = r - l + 1;
		}
		for (int i = 1;i <= n + 1; i++) f[i] = i;
		for (int i = 1;i <= tp; i++) 
			if (len[i] == 1) f[i] = i + 1;
		int ans = 0;
		for (int i = 1;i <= tp; i++) {
			int x = find(i);
			if (x > tp) {
				ans += (tp - i) / 2 + 1;
				break;
			}
			len[x]--; if (len[x] == 1) f[x] = x + 1;
			ans++;
		}
		write(ans);
	}
	return 0;
}