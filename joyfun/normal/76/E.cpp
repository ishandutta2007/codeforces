
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
int n;
ll x[N], y[N];

ll cal(ll *x) {
	ll sum = 0, ans = 0;
	for (int i = 1; i <= n; i++) sum += x[i];
	for (int i = 1; i <= n; i++) ans += 2 * x[i] * x[i] * (n - 1) - 2 * x[i] * (sum - x[i]);
	return ans / 2;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%lld%lld", &x[i], &y[i]);
	printf("%lld\n", cal(x) + cal(y));
	return 0;
}