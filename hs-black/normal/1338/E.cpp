
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

const int N = 8050;
int n; ll ans;
vector<bool> ch[N];
int del[N], num[N], in[N];
char s[N];
int main() {
	read(n); int lim = n / 4;
	for (int i = 1;i <= n; i++) {
		ch[i].resize(n + 5);
		scanf ("%s", s + 1); int st = 0;
		for (int j = 1;j <= lim; j++) {
			int x = isdigit(s[j]) ? s[j] - '0' : s[j] - 'A' + 10;
			st += 4;
			for (int t = 0;t < 4; t++) 
				ch[i][st - t] = x & 1, (x & 1) && (in[st-t]++), x >>= 1;
		}
	}
	static int q[N], L, R;
	L = 1, R = 0;
	for (int i = 1;i <= n; i++) !in[i] && (q[++R] = i);
	ll t = 614 * n + 1; int las = n;
	while (L <= R) {
		int x = q[L]; L++; del[x] = -1;
		ans = ans + t * (--las);
		for (int i = 1;i <= n; i++) 
			ch[x][i] && !(--in[i]) && (q[++R] = i);
	}
//	write(ans);
	if (!las) return write(ans), 0;
//	int x = 0;
	int x = std::max_element(in + 1, in + n + 1) - in;
//	for (int i = 1;i <= n; i++) ~del[i] && (x = i);
	ch[x][x] = 1;
	for (int i = 1;i <= n; i++) !del[i] && (del[i] = ch[i][x]);
	ch[x][x] = 0;
	for (int i = 1;i <= n; i++) if (~del[i])
		for (int j = 1;j <= n; j++) if (~del[i] && ch[i][j])
			num[j] += del[i] != del[j];
	for (int i = 1;i < n; i++) if (~del[i])
		for (int j = i + 1; j <= n; j++) if (~del[j])
			ans += 3 + (del[i] == del[j] && num[i] == num[j]);
	write(ans);
	return 0;
}