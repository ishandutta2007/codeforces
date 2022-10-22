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

int main() {
	int n = read();
	if (n % 2 == 1) {
		puts("YES");
		vi ans(n * 2);
		rep(i, n) {
			if (i & 1) ans[i] = i * 2 + 1, ans[i + n] = i * 2;
			else ans[i] = i * 2, ans[i + n] = i * 2 + 1;
		}
		rep(i, n * 2) printf("%d", ans[i] + 1), putchar(i + 1 == n * 2 ? 10 : 32);
	} else puts("NO");
	return 0;
}