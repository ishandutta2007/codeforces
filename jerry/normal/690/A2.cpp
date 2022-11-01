#include <bits/stdc++.h>
using namespace std;
#define fo(i,a,b) for(int i=(a);i<(b);i++)
#define MOD 1000000007
#define MT make_tuple
#define PB push_back
typedef long long ll;

ll N, G, lo, hi, mid, ans;

int main () {
	cin >> N;
	ans = (N-1)/2;

	for (int MV = 1; MV <= 30; MV++) {

		ll rs = (1LL << MV), re = rs * 2 - 1;

		if (rs > N) break;
		re = min(re, N);

		lo = (N - re + 1) / 2;
		hi = (N - rs) / 2;

		while (lo <= hi) {
			G = (lo + hi) / 2;
			assert((1<<MV)*2 > N - 2*G);
			if (N <= 2*G + (1<<MV)) ans = min(ans, G), hi = G-1;
			else lo = G+1;
		}
	}
	printf("%lld\n", ans);
	return 0;
}