//#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
#define pb push_back
#define __V vector
#define all(x) x.begin(), x.end()
#define oit ostream_iterator
#define mod 1000000007ll

using namespace std;



void doin() {
	cin.tie();
	cout.tie();
	ios::sync_with_stdio(0);
#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
}
template<typename X, typename Y>
istream& operator>>(istream& in, pair<X, Y> &a) {
	in >> a.first >> a.second;
	return in;
}
template<typename T>
void getv(T& i) {
	cin >> i;
}
template<typename T, typename ... Ns>
void getv(vector<T>& v, int n, Ns ... ns) {
	v.resize(n);
	for (auto& i : v)
		getv(i, ns...);
}
template<typename T>
void getv1(T& i) {
	cin >> i;
}
template<typename T, typename ... Ns>
void getv1(vector<T>& v, int n, Ns ... ns) {
	v.resize(n + 1);
	for (int i = 1; i <= n; i++)
		getv(v[i], ns...);
}
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef int _I;
typedef pair<_I, _I> pi;
#define x first
#define y second
bool cmp(pi a, pi b) {
	return (a.x < b.x) || (a.x == b.x && (a.y < b.y));
}
typedef pair<ld, ld> pd;
typedef map<_I, _I> mii;
typedef __V <_I> vi;
typedef __V <char> vc;
typedef __V <ld> vd;
typedef __V <vd> vvd;
typedef __V <pi> vpi;
typedef __V <__V<_I>> vvi;
typedef __V <__V<char>> vvc;
typedef __V <__V<pi>> vvpi;
using AntonTsypko = void;
using arsijo = AntonTsypko;
using god = arsijo;
uniform_real_distribution<double> double_dist(0, 1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
	ll A, B;
	doin();
	ll n, m;
	vi ans = vi(100005);
	vpi a = vpi(106005);
	vpi b = vpi(10005);
	shuffle(all(a), rng);
	shuffle(all(a), rng);
	A = 0;
	B = 0;
	cin >> n >> m;
	for (ll i = 1; i <= m; i++) {
		ll k;
		ll e, r;
		cin >> k >> e >> r;
		if (k == 1) {
			A++;
			a[A].x = e;
			a[A].y = r;
		} else {
			B++;
			b[B].x = e;
			b[B].y = r;
		}
	}

	sort(a.begin() + 1, a.begin() + 1 + A, cmp);

	ll u = 0;
	for (ll i = 1; i <= A; i++) {
		if (i != A) {
			if (a[i].x == a[i + 1].x)
				continue;
		}
		if (ans[a[i].y] != 0)
			continue;
		u++;
		ll v = u;
		if (ans[a[i].x] != 0)
			v = ans[a[i].x];
		for (ll j = a[i].x; j <= a[i].y; j++) {
			ans[j] = v;
		}
	}
	for (ll i = n; i >= 1; i--) {
		if (ans[i] == 0) {
			u++;
			ans[i] = u;
		}
	}
	sort(b.begin() + 1, b.begin() + 1 + B, cmp);
	bool o = 0;
	for (ll i = 1; i <= B; i++) {
		bool e = 0;
		ll pos = 0;

		for (ll j = b[i].x + 1; j <= b[i].y; j++) {

			if (ans[j] < ans[j - 1]) {
				e = 1;
				break;
			}
			if (ans[j] != ans[j - 1] && pos == 0) {
				pos = j - 1;
			}
		}
		if (e)
			continue;
		if (!pos) {
			o = 1;
			break;
		}

		u++;
		ans[pos] = u;

	}
	ans[0] = 1;
	if (!o){
		cout << "YES" << endl;
		for (int i = 1; i <= n; i++) {
			if (!ans[i])
				ans[i] = ans[i - 1];
			cout << ans[i] << " ";
		}
	}else {
		cout << "NO";
	}
}