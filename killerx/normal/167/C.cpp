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

bool ok(ll a, ll b) {
	if (a > b) swap(a, b);
	if (!a) return 0;
	if (!ok(a, b % a)) return 1;
	return !(((b / a) % (a + 1)) & 1);
}

int main() {
	int t = read();
	while (t --) {
		ll a, b; scanf("%lld %lld", &a, &b);
		puts(ok(a, b) ? "First" : "Second");
	}
	return 0;
}