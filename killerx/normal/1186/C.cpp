#pragma GCC optimize(2)
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

char s[1 << 20], t[1 << 20];
int main() {
	scanf("%s%s", s, t);
	int n = strlen(s), m = strlen(t);
	int cnt = 0;
	rep(i, m) cnt += t[i] - '0';
	int ans = 0;
	int nw = 0;
	rep(i, n) {
		nw += s[i] - '0';
		if (i >= m) nw -= s[i - m] - '0';
		if (abs(nw - cnt) & 1) continue;
		if (i >= m - 1) ++ ans;
	}
	printf("%d\n", ans);
	return 0;
}