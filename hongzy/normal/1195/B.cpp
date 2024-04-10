#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back

typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef double db;

ll n, k;

ll check(ll x) {
	ll q = n - x;
	return q * (q + 1) / 2 - x;
}

int main() {
	scanf("%I64d%I64d", &n, &k);
	ll l = 0, r = n - 1, mid, ans = 0;
	while(l <= r) {
		mid = (l + r) >> 1;
		if(check(mid) <= k) r = (ans = mid) - 1;
		else l = mid + 1;
	}
	printf("%I64d\n", ans);
	return 0;
}