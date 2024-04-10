#include <bits/stdc++.h>
#define int ll
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

vi s;
vi gap;
vi sum;

signed main() {
	int n = read();
	rep(i, n) s.pb(read());
	sort(s.begin(), s.end());
	s.erase(unique(s.begin(), s.end()), s.end());
	rep(i, s.size() - 1) gap.pb(s[i + 1] - s[i] - 1);
	sort(gap.begin(), gap.end());
	sum.resize(gap.size() + 1);
	sum[gap.size()] = 0;
	for (int i = ((int) gap.size()) - 1; ~i; -- i) sum[i] = sum[i + 1] + gap[i];
	int q = read();
	while (q --) {
		int l = read(), r = read();
		int x = r - l;
		int ps = lower_bound(gap.begin(), gap.end(), x) - gap.begin();
		printf("%lld%c", (s[s.size() - 1] + x - s[0] + 1) - (sum[ps] - (gap.size() - ps) * x), " \n"[q == 0]);
	}
	return 0;
}