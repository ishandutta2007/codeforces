#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define __V vector
#define vi __V<ll>
#define pi pair<int, int>
#define all(x) x.begin(), x.end()
#define mod 1000000007ll

using namespace __gnu_pbds;
using namespace std;
ll n, l, x, y, t, diff, sum, sp, dp;
bool cx, cy, cdiff, csum;
set<int> can;
vi dps, sps;
int main() {
	cin.tie();
	cout.tie();
	ios::sync_with_stdio(0);
	cx = cy = csum = cdiff = false;
	cin >> n >> l >> x >> y;
	diff = y - x;
	sum = x + y;
	for (int i = 0; i < n; i++) {
		cin >> t;
		can.insert(t);
		if (!cx) {
			if (t == x)
				cx = true;
			else if (t > x && can.find(t - x) != can.end())
				cx = true;
		}
		if (!cy) {
			if (t == y)
				cy = true;
			else if (t > y && can.find(t - y) != can.end())
				cy = true;
		}
		if (t == diff)
			cdiff = true, dps.pb(t);
		else if (t > diff && can.find(t - diff) != can.end())
			cdiff = true, dps.pb(t);

		if (t == sum)
			csum = true, sps.pb(t);
		else if (t > sum && can.find(t - sum) != can.end())
			csum = true, sps.pb(t);

	}
	if (cx && cy)
		return cout << 0, 0;
	for (auto& dp : dps) {
		if (cdiff && (dp + x < l))
			return cout << "1\n" << (dp + x), 0;
		if (cdiff && ((dp - diff - x) > 0))
			return cout << "1\n" << (dp - diff - x), 0;
	}
	for (auto& sp : sps) {
		if (csum)
			return cout << "1\n" << (sp - y), 0;
	}
	if (cy)
		return cout << "1\n" << x, 0;
	if (cx)
		return cout << "1\n" << y, 0;
	return cout << "2\n" << x << " " << y, 0;

}