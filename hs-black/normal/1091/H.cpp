
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

#include <bitset>
const int N = 200050;
int d[N], e[N], sg[N], prime[N], tot, n, f, ans;
bitset<N> mp[102], F;
void init(int n, int k) {
	for (int i = 2;i <= n; i++) {
		if (!e[i]) prime[++tot] = e[i] = i, d[i]++;
		for (int j = 1;j <= tot && prime[j] * i <= n; j++) {
			int t = prime[j] * i; e[t] = prime[j], d[t] = d[i] + 1;
			if (prime[j] == e[i]) break;
		}
		if (d[i] <= 2 && i != k) F.set(i, 1);
	}
	mp[0] = F | (F << 1);
	for (int i = 2;i <= n; i++) {
		while (mp[sg[i]][i]) sg[i]++;
		mp[sg[i]] |= F << i;
	}
}

int main() {
	read(n), read(f); init(2e5, f);
	for (int i = 1, b, w, r;i <= n; i++)
		read(b), read(w), read(r), ans = ans ^ sg[w - b - 1] ^ sg[r - w - 1];
	puts(ans ? "Alice" : "Bob");
	puts(!ans ? "Alice" : "Bob");
	return 0;
}