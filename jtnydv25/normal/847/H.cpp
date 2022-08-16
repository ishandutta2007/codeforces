#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int N = 100005;

int n;
ll a[N];
ll inc[N], decl[N], lsum[N], rsum[N];
ll lmx[N], rmx[N];

int main() {
	scanf("%d", &n);
	for (int i=1; i<=n; i++) {
		scanf("%lld", a+i);
		lmx[i] = max(lmx[i-1] + 1, a[i]);
		inc[i] = inc[i-1] + lmx[i] - a[i];
		// cout << i << ": " << inc[i] << endl;
	}
	for (int i=n; i; i--) {
		rmx[i] = max(rmx[i+1] + 1, a[i]);
		decl[i] = decl[i+1] + rmx[i] - a[i];
		// cout << i << ": " << decl[i] << endl;
	}
	ll ans = 1e18;
	for (int i=1; i<=n; i++) {
		ll la = inc[i] + decl[i] - min(lmx[i]-a[i], rmx[i]-a[i]);
		// cout << i << ": " << la << endl;
		ans = min(ans, la);
	}
	printf("%lld\n", ans);

	return 0;
}