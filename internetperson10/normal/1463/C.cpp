#include <bits/stdc++.h>
#define int long long
using namespace std;

bool between(int x, int y, int z) {
	// cout << x << ' ' << y << ' ' << z << '\n';
	if(abs(x-z) + abs(z-y) == abs(x-y)) return true;
	return false;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n, le, ri, s, st, ans;
		le = ri = s = st = ans = 0;
		int ti, t2, x = 100000000001;
		cin >> n;
		while(n--) {
			cin >> t2;
			if(x != 100000000001) {
				if(st == s) ans++;
				else if(between(le + ((ri-le)/(st-s))*(min(st, ti)-s), le + ((ri-le)/(st-s))*(min(st, t2)-s), x)) ans++;
			}
			ti = t2;
			cin >> x;
			if(ti >= st) {
				le = ri;
				ri = x;
				s = ti;
				st = ti + abs(le-ri);
			}
		}
		t2 = 100000000001;
		if(st == s) ans++;
		else if(between(le + ((ri-le)/(st-s))*(min(st, ti)-s), le + ((ri-le)/(st-s))*(min(st, t2)-s), x)) ans++;
		cout << ans << '\n';
	}
}