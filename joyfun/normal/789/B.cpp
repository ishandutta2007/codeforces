#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()

const int N = 100005;
ll b, q, l, m, a[N];
map<ll, int> vis;

int main() {
	scanf("%lld%lld%lld%lld", &b, &q, &l, &m);
	while (m--) {
		ll x; scanf("%lld", &x);
		vis[x] = 1;
	}
	if (max(-b, b) > l) {
		printf("0\n");
	} else if (b == 0) {
		if (vis.count(b) == 0) printf("inf\n");
		else printf("0\n");
	} else {
		if (q == 0) {
			if (vis.count(0) == 0) {
				printf("inf\n");
			} else {
				printf("%d\n", !vis.count(b));
			}
		} else if (q == 1) {
			if (vis.count(b) == 0) printf("inf\n");
			else printf("0\n");
		} else if (q == -1) {
			if (vis.count(b) == 0 || vis.count(-b) == 0) printf("inf\n");
			else printf("0\n");
		}else {
			int ans = 0;
			while (max(-b, b) <= l) {
				if (vis.count(b) == 0) ans++;
				b *= q;
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}