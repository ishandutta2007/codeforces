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

int n, m;
char s[1005], t[1005];

int main() {
	n = read(), m = read();
	scanf("%s%s", s, t);
	int mn = inf;
	vi ans;
	rep(i, m) if (i + n <= m) {
		int cur = 0;
		vi curv;
		rep(j, n) {
			if (s[j] != t[i + j]) {
				cur ++;
				curv.pb(j);
			}
		}
		if (cur < mn) mn = cur, ans = curv;
	}
	printf("%d\n", mn);
	rep(i, mn) printf("%d%c", ans[i] + 1, " \n"[i + 1 == mn]);
	return 0;
}