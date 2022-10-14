#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 1<<20, mod = 1e9 + 7;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
bool can(ld x1, ld y1, ld x2, ld y2, ld v, ld t, ld a, ld b, ld c, ld d, ld T) {
	if(T < t) x1 += a*T, y1 += b*T;
	else {
		x1 += a*t, y1 += b*t;
		x1 += c*(T-t), y1 += d*(T-t);
	}
	ld dist = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	return (dist/v) <= T;
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	ld x1, y1, x2, y2, v, t, A, B, C, D;
	cin >> x1 >> y1 >> x2 >> y2 >> v >> t >> A >> B >> C >> D;
	ld l = 0, r = 1e18, mid;
	while(r-l > 1e-8) {
		mid = (l+r)/2;
		if(!can(x1, y1, x2, y2, v, t, A, B, C, D, mid)) l = mid;
		else r = mid;
	}
	
	cout << fixed << setprecision(15) << mid << endl;
}