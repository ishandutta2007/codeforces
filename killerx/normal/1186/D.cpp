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

int n;
int main() {
	n = read();
	vi ans, xs, sg;
	ll sum = 0;
	rep(i, n) {
		char c[25]; scanf("%s", c);
		int a = 0, b = 0, sgn = 1;
		int j = 0;
		if (c[0] == '-') sgn = 0, ++ j;
		while (c[j] != '.') a = a * 10 + c[j] - '0', ++ j;
		if (!sgn) a = -a;
		++ j;
		while (c[j]) b = b * 10 + c[j] - '0', ++ j;
		ans.pb(a); xs.pb(b); sg.pb(sgn); sum += a;
	}
	if (sum > 0) {
		int i = 0;
		while (sum) {
			while (!xs[i] || sg[i]) ++ i;
			-- ans[i];
			++ i;
			-- sum;
		}
	} else {
		int i = 0;
		while (sum) {
			while (!xs[i] || !sg[i]) ++ i;
			++ ans[i];
			++ i;
			++ sum;
		}
	}
	rep(i, n) {
		printf("%d\n", ans[i]);
	}
	return 0;
}