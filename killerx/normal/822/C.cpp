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

int n, x;
int l[200005], r[200005], c[200005];
multiset <int> costs[200005];
int id1[200005], id2[200005];

bool cmp1(int a, int b) {return l[a] < l[b];}
bool cmp2(int a, int b) {return r[a] < r[b];}

int main() {
	n = read(), x = read();
	rep(i, n) {
		l[i] = read(), r[i] = read(), c[i] = read();
		id1[i] = id2[i] = i;
	}
	sort(id1, id1 + n, cmp1);
	sort(id2, id2 + n, cmp2);
	rep(i, n) costs[r[i] - l[i] + 1].insert(c[i]);
	int j = n - 1;
	ll ans = 1e18;
	for (int i = n - 1; ~i; -- i) {
		while (~j && r[id2[j]] >= l[id1[i]]) {
			costs[r[id2[j]] - l[id2[j]] + 1].erase(costs[r[id2[j]] - l[id2[j]] + 1].find(c[id2[j]]));
			-- j;
		}
		if (r[id1[i]] - l[id1[i]] + 1 >= x) continue;
		if (costs[x - (r[id1[i]] - l[id1[i]] + 1)].empty()) continue;
		ans = min(ans, 0LL + c[id1[i]] + *costs[x - (r[id1[i]] - l[id1[i]] + 1)].begin());
	}
	printf("%lld\n", ans == 1e18 ? -1 : ans);
	return 0;
}