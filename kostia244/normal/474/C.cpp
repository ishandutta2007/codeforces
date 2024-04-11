#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
#define M_PI 3.14159265358979323846
using namespace std;
using ll = long long;
using vi = vector<ll>;
using ld = ll;
using vec = complex<ld>;
const ld eps = 1e-7;
ld dot(vec a, vec b) {
	return (conj(a) * b).real();
}
ld cross(vec a, vec b) {
	return (conj(a) * b).imag();
}
istream& operator>>(istream& in, vec& p) {
	ld x, y;
	in >> x >> y;
	p = vec(x, y);
	return in;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
struct molt {
	vec p, o;
};

ll check(vector<molt> v, int mask) {
	int ans = 0;
	for(auto &i : v) {
		int t = mask%4;
		mask/=4;
		i.p-=i.o;
		int x = i.p.real();
		int y = i.p.imag();
		while(t--) {
			ans++;
			swap(x, y);
			x*=-1;
		}
		i.p = vec(x, y);
		i.p += i.o;
	}
	for(int i = 0; i < 4; i++)
		if(v[i].p == v[(i+1)%4].p)
			return INT_MAX;
	sort(v.begin(), v.end(), [&v](const molt a, const molt b) {
		if(a.p == b.p)
			return false;
		if(a.p == v[0].p)
			return true;
		if(b.p == v[0].p)
			return false;
		return cross(a.p-v[0].p, b.p-v[0].p) < 0;
	});
	for(int i = 0; i < 4; i++)
		if(norm(v[i].p-v[(i+1)%4].p) != norm(v[(i+2)%4].p-v[(i+1)%4].p))
			return INT_MAX;
	if(norm(v[0].p-v[2].p) != norm(v[1].p-v[3].p))
		return INT_MAX;
	return ans;
}

void solve() {
	vector<molt> a;
	a.resize(4);
	for (auto &i : a)
		cin >> i.p >> i.o;
	ll ans = INT_MAX;
	for (int i = 0; i < 1<<8; i++)
		ans = min(ans, check(a, i));
	if (ans == INT_MAX)
		ans = -1;
	cout << ans << "\n";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	while (n--)
		solve();
}