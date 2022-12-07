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

const int N = 1005;
const ll inf = (1ll<<60);
int n, m, k, p, a[N][N];
int rs, cs;
priority_queue<ll> r, c;
ll sr[N * N], sc[N * N];

int main() {
	scanf("%d%d%d%d", &n, &m, &k, &p);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
	for (int i = 1; i <= n; i++) {
		ll s = 0;
		for (int j = 1; j <= m; j++)
			s += a[i][j];
		r.push(s);
	}
	for (int i = 1; i <= m; i++) {
		ll s = 0;
		for (int j = 1; j <= n; j++)
			s += a[j][i];
		c.push(s);
	}
	for (int i = 1; i <= k; i++) {
		ll a = r.top(), b = c.top();
		sr[i] = sr[i - 1] + a;
		sc[i] = sc[i - 1] + b;
		r.pop();
		r.push(a - m * p);
		c.pop();
		c.push(b - n * p);
	}
	ll ans = -inf;
	for (int i = 0; i <= k; i++)
		ans = max(ans, sr[i] + sc[k - i] - 1ll * i * p * (k - i));
	printf("%lld\n", ans);
	return 0;
}