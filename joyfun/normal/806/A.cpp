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

int T;
ll x, y, p, q;

ll ceil(ll a, ll b) {
	return (a + b - 1) / b;
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%lld%lld%lld%lld", &x, &y, &p, &q);
		if (p == q) {
			if (x == y) printf("0\n");
			else printf("-1\n");
		} else if (p == 0) {
			if (x == 0) printf("0\n");
			else printf("-1\n");
		} else printf("%lld\n", max(ceil(x, p), max(ceil(y, q), ceil(y - x, q - p))) * q - y);
	}
	return 0;
}