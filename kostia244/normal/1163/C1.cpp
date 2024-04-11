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
#define mod 1234567891ll
using namespace __gnu_pbds;
using namespace std;
void doin() {
	cin.tie();
	cout.tie();
	ios::sync_with_stdio(0);
#ifdef LOCAL
//		freopen("in", "r", stdin);
//		freopen("out", "w", stdout);
#endif
}
template<typename T, typename l>
void getv(T& a, int n, l f) {
	a.resize(n);
	for (auto& i : a)
		cin >> i, f(i);
}
template<typename T>
void getv(T& a, int n) {
	a.resize(n);
	for (auto& i : a)
		cin >> i;
}
typedef unsigned long long ull;
typedef long long ll;
typedef double ld;
typedef ll _I;
typedef pair<_I, _I> pi;
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
struct line {
	int a, b, c;
	line(int x1, int x2, int y1, int y2) {
		a = y1 - y2;
		b = x1 - x2;
		c = x2 * y1 - x1 * y2;
		int t = __gcd(__gcd(a, b), c);
		a /= t;
		b /= t;
		c /= t;
		if (a < 0)
			a *= -1, b *= -1, c *= -1;
	}
	void print() {
		cout << a << " " << b << " " << c << "\n";
	}
	bool operator<(const line& o) const {
		if (a < o.a)
			return true;
		else if (a == o.a) {
			if (b < o.b)
				return true;
			else if (b == o.b)
				if (c < o.c)
					return true;
		}
		return false;
	}
	bool operator==(const line& o) const {
		return (a == o.a && b == o.b && c == o.c);
	}
	bool operator!=(const line& o) const {
		return (a != o.a || b != o.b || c != o.c);
	}
};
ll n, ans = 1;
vpi a;
__V<line> l;

int main() {
	cin >> n;
	a.resize(n);
	for (auto& i : a)
		cin >> i.first >> i.second;
	for (auto i : a)
		for (auto j : a) {
			if (i == j)
				continue;
			l.eb(i.first, j.first, i.second, j.second);
		}
	sort(all(l));
	for (int i = 1; i < l.size();i++)
		if (l[i] != l[i - 1])
			ans++;
	ans = (ans-1)*ans/2;
	ll bl = 1;
	for (int i = 1; i < l.size();i++)
		if (l[i-1].a == l[i].a && l[i-1].b == l[i].b) {
			if(l[i-1].c != l[i].c)
				bl++;
		} else
			ans -= bl*(bl-1)/2, bl = 1;
	ans -= bl*(bl-1)/2, bl = 1;
	cout << ans;
}