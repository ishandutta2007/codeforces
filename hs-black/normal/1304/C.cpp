#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
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

const int N = 205;
int T;
ll n, fi;
struct node {
	ll u, d, t;
	bool operator < (const node &i) const {
		return t < i.t;
	}
}a[N];

int main() {
	read(T);
	while (T--) {
		read(n), read(fi);
		for (int i = 1;i <= n; i++) 
			read(a[i].t), read(a[i].d), read(a[i].u);
		sort(a + 1, a + n + 1);
		ll pre = 0, up = fi, down = fi;
		int fl = 1;
		for (int i = 1;i <= n; i++) {
			up += a[i].t-pre;
			down -= a[i].t-pre;
			up = min(up, a[i].u), down = max(down, a[i].d);
			if (up < down) {
				fl = 0; break;
			}
			pre = a[i].t;
		}
		if (fl) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
/*

4
2 12
5 7 10
10 16 20
3 0
5 1 2
7 3 5
10 -1 0
3 -100
100 0 0
100 -50 50
200 100 100
1 100
99 -100 0


*/