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

const ll inf = (1ll<<60);
const int N = 105;

int n;
struct S {
	int k, c;
	void read() {
		scanf("%d%d", &k, &c);
	}
	bool operator < (const S& x) {
		return c < x.c;
	}
} s[N];
int t;
ll p[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) s[i].read();
	sort(s + 1, s + 1 + n);
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) scanf("%lld", &p[i]);
	for (int i = t; i >= 1; i--) p[i] -= p[i - 1];
	p[t + 1] = inf;
	t++;
	int j = 1;
	ll ans = 0;
	int i = 1;
	while (1) {
		while (i <= t && p[i] == 0) i++; if (i > t) break;
		while (j <= n && s[j].k == 0) j++; if (j > n) break;
		int use = min(p[i], 1ll * s[j].k);
		ans += 1ll * use * s[j].c * i;
		p[i] -= use; s[j].k -= use;
	}
	printf("%lld\n", ans);
	return 0;
}