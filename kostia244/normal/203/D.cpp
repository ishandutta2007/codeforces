#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define xx first.first
#define yy first.second
#define __V vector
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define oit ostream_iterator
#define mod 1000000007ll
using namespace __gnu_pbds;
using namespace std;
void doin() {
	cin.tie();
	cout.tie();
	ios::sync_with_stdio(0);
#ifdef LOCAL
//	freopen("in", "r", stdin);
#endif
}

template<typename T>
void getv(T& a, int n) {
	a.resize(n);
	for (auto& i : a)
		cin >> i;
}

typedef long long ll;
typedef ll _I;
typedef double ld;
typedef pair<_I, _I> pi;
typedef pair<ld, ld> pd;
typedef map<_I, _I> mii;
typedef __V <_I> vi;
typedef __V <char> vc;
typedef __V <ld> vd;
typedef __V <pi> vpi;
typedef __V <__V<_I>> vvi;
typedef __V <__V<char>> vvc;
typedef __V <__V<pi>> vvpi;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ld a, b, m, p[3], v[3];

ld coltime() {
	return min(
			{ (v[0] != 0 ? (((a * (v[0] > 0)) - p[0]) / v[0]) : 1000000),
					(-(p[1] / v[1])), (
							v[2] != 0 ?
									(v[2] > 0 ?
											((b - p[2]) / v[2]) :
											((-p[2]) / v[2])) :
									1000000) });
}

int main() {
	doin();
	cin >> a >> b >> m;
	for (int i = 0; i < 3; i++)
		cin >> v[i];
	p[0] = a / 2.0;
	p[1] = m;
	p[2] = 0;
//	cout << fixed << setprecision(6) << m  << " " << p[0] << " " << p[1] << " " << p[2] << "\n";
	while (fabs(p[1]) > 1e-7) {
		m = coltime();
//		cout << b << " " << v[2] << "\n"
//		cout <<  << "\n";
		for (int i = 0; i < 3; i++) {
			p[i] = (p[i] + m * v[i]);
			if (fabs(p[i]) < 1e-6 || (i == 0 && fabs(p[i] - a) < 1e-6)
					|| (i == 2 && fabs(p[i] - b) < 1e-6))
				v[i] = -v[i];
		}
	}
	cout << fixed << setprecision(6) << p[0] << " " << p[2] << "\n";
}