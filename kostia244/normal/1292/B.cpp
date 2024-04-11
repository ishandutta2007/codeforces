#pragma GCC optimize("trapv")
//#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
const int maxn = 2e5 + 555;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mx = 1ll << 61;
vector<pi> ps;
ll ax, ay, bx, by, xs, ys;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ps.resize(1);
	cin >> ps[0].first >> ps[0].second;
	ll t = 0, ans = 0;
	cin >> ax >> ay >> bx >> by >> xs >> ys >> t;
	while (true) {
		if (ps.back().first > mx / 100)
			break;
		if (ps.back().second > mx / 100)
			break;
		ps.pb( { ps.back().first * ax + bx, ps.back().second * ay + by });
	}
	for (int s = 0; s < ps.size(); s++) {
		pi cur = { xs, ys };
		ll z = 0;
		for (ll d = s; d < ps.size(); d++) {
			z += abs(cur.first - ps[d].first);
			z += abs(cur.second - ps[d].second);
			cur = ps[d];
			if (z > t)
				break;
//			cout << s << " " << d << " " << z << "\n";
			ans = max(ans, d - s + 1);
		}
		cur = { xs, ys };
		z = 0;
		for (ll d = s; d>=0; d--) {
			z += abs(cur.first - ps[d].first);
			z += abs(cur.second - ps[d].second);
			cur = ps[d];
			if (z > t)
				break;
//			cout << s << " " << d << " " << z << "f\n";
			ans = max(ans, s - d + 1);
		}
	}
	cout << ans;
}