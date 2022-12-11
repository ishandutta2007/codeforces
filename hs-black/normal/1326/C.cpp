#include <queue>
#include <vector>
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

const int N = 300500;
const int P = 998244353;
int p[N], n, k;
ll mx = 0, ans = 1;
int main() {
	read(n), read(k);
	for (int i = 1;i <= n; i++) read(p[i]);
	for (int i = n;i > n - k; i--) mx += i;
	int now = 1, tmp = 0;
	int lim = n, i = 1;
	while (p[lim] <= n - k) lim--;
	while (p[i] <= n - k) i++;
	for (;i <= lim; i = now + 1) {
		tmp = 1; now = i;
		while (now <= n && p[now] <= n - k) now++, tmp++;
		ans = ans * tmp % P;
	}
	cout << mx << ' ' << ans << endl;
	return 0;
}