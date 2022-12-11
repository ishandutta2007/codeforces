#include <iostream>
#include <queue>
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

priority_queue<ll> q;

const int N = 10050;
ll n, k, a[N];
int main() {
	int T; read(T);
	while (T--) {
		read(n), read(k); ll t = 1;
		for (int i = 1;i <= n; i++) {
			read(a[i]); if (a[i] != 0) q.push(a[i]);
		}
		if (q.empty()) {
			cout << "YES\n";
			continue;
		}
		while (t < q.top()) t *= k;
		while (t && q.size()) {
			ll p = q.top(); q.pop();
			if (p >= t) p -= t;
			if (p) q.push(p);
			t /= k;
		}
		if (q.empty()) cout << "YES\n";
		else cout << "NO\n";
		while (q.size()) q.pop();
	}
	return 0;
}
/*
1
3 9
0 59049 810

*/