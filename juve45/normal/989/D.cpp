#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, k, l, wmax, w, x, i, ans, le, ri;
vector <ll> p, q;
bool ok(ll a, ll b) {
	if(b<a) return 0;
	a=2*a+l, b=2*b+l;
	ll d = (b - (a+b)/2 +l)*wmax;
	if(d > abs((a+b)/2)) return 1;
	return 0;
}
int main() {
	for(cin >> n >> l >> wmax, i=1; i<=n; i++) {
		cin >> x >> w;
		if(w==1) p.push_back(x);
		else q.push_back(x);
	}
	sort(p.begin(),p.end());sort(q.begin(),q.end());
	for(ll i = 0; i < p.size(); i++) {
		while(le < q.size() && !ok(p[i], q[le])) le++;
		if(le > ri) ri = le;
		while(ri < q.size() && ok(p[i], q[ri])) ri++;
		ans += ri-le;
	}
	cout << ans << '\n';
}