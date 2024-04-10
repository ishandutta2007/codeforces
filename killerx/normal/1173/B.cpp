#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int mod = 1000000007;
#define pb push_back
#define mp make_pair
using ll = long long;
using vi = vector <int>;
using pii = pair <int, int>;
#define rep(i,n) for (int i = 0; i < (int) (n); ++ i)
#define foreach(it,c) for (auto it = c.begin(); it != c.end(); ++ it)

inline int read() {
	int x = 0, f = 1, c = getchar();
	for (;!isdigit(c);c = getchar()) if (c == 45) f ^= 1;
	for (; isdigit(c);c = getchar()) x = x * 10 + c - 48;
	return f ? x : -x;
}

int ans[1005][2];
int main() {
	int n = read();
	int r = 1, c = 1;
	int m = 0;
	rep(i, n) {
		ans[i][0] = r;
		ans[i][1] = c;
		m = max(m, max(r, c));
		if (i & 1) r ++;
		else c ++;
	}
	printf("%d\n", m);
	rep(i, n) printf("%d %d\n", ans[i][0], ans[i][1]);
	return 0;
}