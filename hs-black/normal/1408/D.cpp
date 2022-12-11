
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

const int N = 2005000;
int m, n, c[N], d[N], a[N], b[N], ls, rs, ans, cnt[N];
vector<int> v[N]; 
int main() {
	read(n), read(m);
	for (int i = 1;i <= n; i++) read(a[i]), read(b[i]);
	for (int i = 1;i <= m; i++) read(c[i]), read(d[i]);
	for (int i = 1;i <= n; i++) {
//		ls = rs = 0;
		for (int j = 1;j <= m; j++) {
			if (c[j] >= a[i] && d[j] >= b[i])
				v[c[j] - a[i] + 1].push_back(d[j] - b[i] + 1), cnt[d[j] - b[i] + 1]++;
//				Mx(ls, c[j] - a[i] + 1), Mx(rs, d[j] - b[i] + 1);
		}
//		v[ls].push_back(rs); s.insert(rs);
	}
	int ans = 1e9, mx = 1000002;
	while (mx && !cnt[mx]) mx--;
	Mn(ans, mx);
	for (int i = 0;i <= 1000002; i++) {
		if (!v[i].size()) continue;
		for (auto t: v[i]) cnt[t]--;
		while (mx && !cnt[mx]) mx--;
		Mn(ans, i + mx);
	}
	write(ans);
	return 0;
}