/*

 
| _ _|
 ` _x 
  /  |
 /  c ?
| |||
| (c_c_)_)


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

const int N = 205000;
int T, n, k, cnt[N], a[N];
int main() {
	
	for (read(T); T; T--) {
		read(n), read(k);
		memset(cnt, 0, (n + 5) * 4);
		for (int i = 1;i <= n; ++i) read(a[i]), cnt[a[i]]++;
		
		int sum = -n, ans = n, x, y, st = 1;
		for (int l = 1, r = 0;l <= n; sum -= cnt[l++] * 2) {
			while (r <= n && sum < k) sum += cnt[++r] * 2;
			if (r > n) break;
			if (ans > r - l) ans = r - l, x = l, y = r;
		}
		write(x, ' '), write(y);
		for (int i = 1;i < k; ++i) {
			sum = 0;
			for (int j = st;j <= n; ++j) {
				sum += a[j] >= x && a[j] <= y;
				sum -= a[j] < x || a[j] > y;
				if (sum > 0) { write(st, ' '), write(j); st = j + 1; break; }
			}
		}
		write(st, ' '), write(n);
	}
	return 0;
}