#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
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

const int N = 205000;
ll a[N], ans, n;
map<ll, int> mp;
void check(ll k) {
	ll res = 0; if (mp[k]) return; mp[k] = 1;
	for (int i = 1;i <= n; i++) {
		if (a[i] >= k) res += min(a[i] % k, k - a[i] % k);
		else res += k - a[i];
		if (res >= ans) return;
	}
	ans = min(ans, res); 
}

void work(ll x) {
	for (ll i = 2;i * i <= x; i++) {
		if (x % i) continue;
		while (x % i == 0) x /= i;
		check(i);
	}
	if (x > 1) check(x);
}

#include <cstdlib>
#include <ctime>
int main() {
// 	freopen ("hs.in","r",stdin);
//	srand(time(0));
	read(n); ans = n; 
	for (int i = 1;i <= n; i++) read(a[i]);
	random_shuffle(a + 1, a + n + 1);
	int lim = min(n, 300ll);
	for (int i = 1;i <= lim; i++) {
		ll x = a[i];
		work(x), work(x + 1); if (x > 1) work(x - 1);
	}
	cout << ans << endl;
	return 0;
}