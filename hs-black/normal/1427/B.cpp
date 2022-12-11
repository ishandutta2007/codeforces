
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
int T, n, k;
char s[N];
int st[N], tp;
int main() {
	for (read(T); T; T--) {
		read(n), read(k);
		scanf ("%s", s + 1);
		int pre = tp = 0, cnt = 0, ans = 0;
		for (int i = 1;i <= n; i++) {
			if (s[i] == 'L') continue;
			int l = i, r = i;
			while (r <= n && s[r+1] == 'W') r++;
			ans += (r - l + 1) * 2 - 1, i = r;
		}
		for (int i = 1;i <= n; i++) cnt += s[i] == 'L';
		for (int i = 1;i <= n; i++) {
			if (s[i] == 'W') { pre = 1; continue; }
			if (!pre) continue;
			int l = i, r = i;
			while (r <= n && s[r+1] == 'L') r++;
			if (r != n) st[++tp] = r - l + 1, i = r;
		}
		sort(st + 1, st + tp + 1);
		if (cnt == n) { Mn(n, k), write(max(k * 2 - 1, 0)); continue; }
		ans += min(cnt, k) * 2;
		for (int i = 1;i <= tp; i++) 
			if (k >= st[i]) k -= st[i], ans++;
		write(ans);
	}
	return 0;
}