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

const int N = 1000005;
const ll inf = 1ll<<60;
int n, m, a[N];


ll cal(int x) {
	int v;
	ll ans = 0;
	for (v = 1; v <= n; v++) if (a[v] > x) break; v--;
	for (int i = 1; i <= v; i += m) ans += 2ll * (x - a[i]);
	for (int i = n; i > v; i -= m) ans += 2ll * (a[i] - x);
	return ans;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	printf("%lld\n", cal(a[(n + 1) / 2]));
	return 0;
}