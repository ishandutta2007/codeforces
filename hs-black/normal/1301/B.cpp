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

const int N = 200050;
ll mx, mn;
ll a[N], n;

const ll INF = 0x7fffffff;

inline int jue(int x) {
	return x > 0 ? x : -x;
}
bool check(int mid) {
	mx = INF, mn = 0;
	for (int i = 1;i <= n; i++) {
		if (a[i] == -1) continue;
		if (a[i-1] == -1 || a[i+1] == -1) {
			mx = min(mx, a[i]+mid);
			mn = max(mn, a[i]-mid);
			if (mn > mx) return 0;
		}	
	}
	return 1;
}

int main() {
	int T; read(T);
	while (T--) {
		read(n);
		int l = 0;
		for (int i = 1;i <= n; i++) {
			read(a[i]);
			if (a[i] == -1 || a[i-1] == -1) continue;
			if (i != 1) l = max(l, jue(a[i]-a[i-1]));
		}
		a[0] = a[1], a[n+1] = a[n];
		int r = 1000000000;
		ll ans = l;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (check(mid)) r = mid - 1, ans = mn;
			else l = mid + 1;
		}
		write(l), putchar(' '), write(ans), putchar('\n');
	}
	return 0;
}