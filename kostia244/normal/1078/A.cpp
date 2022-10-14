#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vi>;
const ll mod = 1000000007;

int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	ld a, b, c, x1, y1, x2, y2, ans;
	cin >> a >> b >> c >> x1 >> y1 >> x2 >> y2;
	ans = fabs(x1-x2)+fabs(y1-y2);
	vector<pair<ld, ld>> l, r;
	l.pb({(-b*y1-c)/a, y1});
	l.pb({x1, (-a*x1-c)/b});
	r.pb({(-b*y2-c)/a, y2});
	r.pb({x2, (-a*x2-c)/b});
	for(auto i : l)
		for(auto j : r) {
			ld t = fabs(i.first-x1)+fabs(i.second-y1)+fabs(j.first-x2)+fabs(j.second-y2);
			t += hypot(i.first-j.first, i.second-j.second);
			ans = min(ans, t);
		}
	cout << fixed << setprecision(15);
	cout << ans;
}