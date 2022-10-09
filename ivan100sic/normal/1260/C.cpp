// I've decided to retire from ALL contests
// It's been a nice ride... but I need to move on
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

void ans(bool x) {
	cout << (x ? "REBEL\n" : "OBEY\n");
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		ll r, b, k;
		cin >> r >> b >> k;
		if (r > b)
			swap(r, b);
		if (b % r == 0) {
			ans(b / r - 1 >= k);
		} else {
			int g = gcd(b, r);
			b /= g;
			r /= g;
			ll lo = 0, hi = 2e9, o = -1;
			while (lo <= hi) {
				ll mid = (lo + hi) / 2;
				if ((mid - 1) * r + 1 <= b-1) {
					o = mid;
					lo = mid + 1;
				} else {
					hi = mid - 1;
				}
			}
			ans(o >= k);
		}
	}
}

// I will still practice daily...

// r.r.r.r.r.r.r.r.r.r.r.r.r.r.r.r.r.r.r.r.r.r
// b......b......b......b......b......b......b
// b r r rbr r r b r r rbr r r b

// rrrrrrrrrrrrr
// b...b...b...b
// brrrbrrrbrrrb

// r..r..r..r..r..r..r..r..r..r..r..r..r..r..r
// b......b......b......b......b......b......b
// b  r  rb r  r br  r  b  r  rb r  r br  r  b