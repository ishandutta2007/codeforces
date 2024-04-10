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

const int N = 205;
int n, f[N], vis[N];

ll lcm(ll a, ll b) {
	return a / __gcd(a, b) * b;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &f[i]);
	int Max = 0;
	ll a = 1;
	for (int i = 1; i <= n; i++) {
		int u = i, c = 0;
		memset(vis, 0, sizeof(vis));
		while (!vis[u]) {
			vis[u] = ++c;
			u = f[u];
		}
		a = lcm(a, c - vis[u] + 1);
		Max = max(Max, vis[u] - 1);
	}
	//printf("%lld %d\n", a, Max);
	if (Max == 0) printf("%lld\n", a);
	else printf("%lld\n", (Max + a - 1) / a * a);
	return 0;
}