#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define ll long long
using namespace std;

template <typename T>
void read(T &x) {
    x = 0; bool f = 0;
    char c = getchar();
    for (;!isdigit(c);c=getchar()) if (c=='-') f=1;
    for (;isdigit(c);c=getchar()) x=x*10+(c^48);
    if (f) x=-x;
}

template <typename T>
void write(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x >= 10) write(x / 10);
    putchar('0' + x % 10);
}

const int N = 406005;
const int Maxn = 40000005;
ll k;
struct Tree {
	int d[Maxn];
	
	inline void add(int x) {
		for (;x <= k; x += x & -x) d[x]++;
	}
	
	inline int ask(int x) {
		int res = 0;
		for (; x ; x -= x & -x) res += d[x];
		return res;
	}
	
}t1, t2;

ll n, lim, a[N];
ll ans;
int main() {
	read(n);
	for (int i = 1;i <= n; i++) 
		read(a[i]), lim = max(lim, (ll)(log(a[i])/log(2)) + 1);
	for (int j = 0;j <= lim; j++) {
		ll P = (1 << j) - 1, res = 0;
		k = P + 1;
		for (register int i = 1;i <= n; i++) {
			int tmp = a[i] & P, di = (a[i] >> j) & 1; tmp++;
			if (di) res += t1.ask(P + 1) - t1.ask(P - tmp + 2) + t2.ask(P - tmp + 2), t1.add(tmp);
			else res += t1.ask(P - tmp + 2) + t2.ask(P + 1) - t2.ask(P - tmp + 2), t2.add(tmp);
		}
		ans += (res & 1) * (1 << j);
		for (register int i = 0;i <= P + 1; i++) t1.d[i] = t2.d[i] = 0;
	}
	cout << ans << endl;
	return 0;
}
/*
4 
10000000 20000000 5342678 5687231

*/