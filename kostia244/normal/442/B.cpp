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
//  freopen("input.txt", "r", stdin);
#endif
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
int n;
ld p0, p1, tp0, tp1;
vd a;

int main() {
	doin();
	cin >> n;
	a.resize(n);
	for (auto& i : a)
		cin >> i;
	sort(all(a), greater<ld>());
	p0 = 1.0 - (p1 = a[0]);
	for (int i = 1; i < n; i++) {
		tp0 = p0 * (1.0 - a[i]);
		tp1 = (p1 * (1.0 - a[i])) + (p0 * a[i]);
		if(tp1 > p1) {
			p1 = tp1;
			p0 = tp0;
		}
	}
	cout << fixed << setprecision(15) << p1;
}