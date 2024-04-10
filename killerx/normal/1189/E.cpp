#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector <int>
#define pii pair <int, int>
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,n) for (int i = 0; i < (int) (n); ++ i)
#define foreach(it,c) for (__typeof(c.begin()) it = c.begin(); it != c.end(); ++ it)

inline int read() {
	int x = 0, f = 1, c = getchar();
	for (;!isdigit(c);c = getchar()) if (c == '-') f ^= 1;
	for (; isdigit(c);c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}

int n, k, p;
int a[300005];
map <int, int> cnt;
ll ans;

int main() {
	n = read(), p = read(), k = read();
	rep(i, n) {
		a[i] = read();
		int v = (1LL * a[i] * a[i] % p * a[i] % p * a[i] % p - 1LL * k * a[i] % p + p) % p;
		ans += cnt[v];
		cnt[v] ++;
	}
	printf("%lld\n", ans);
	return 0;
}