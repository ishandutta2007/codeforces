#pragma GCC optimize ("Ofast")
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
ld n, m, w, targ, v[1000], EPS = 1e-7;
__V<__V<pd>> ans;
int main() {
	doin();
	cout << fixed << setprecision(7);
	cin >> n >> w >> m;
	ans.resize(m);
	targ = (n * w) / m;
	for (int i = 0; i < m; i++)
		v[i] = targ;
	for (int i = 0; i < n; i++) {
		ld left = w, add;
		int c = 0;
		for (int j = 0; j < m; j++) {
			add = min(v[j], left);
			if (c == 0 && add > EPS) {
				left -= add;
				v[j] -= add;
				ans[j].pb( { i + 1, add });
				c++;

				if (abs(left) < EPS)
					break;
			} else if (add >= EPS) {
				v[j] -= left;
				ans[j].pb( { i + 1, left });
				left = 0;
				break;
			}
		}
		if (abs(left) > EPS) {
			return cout << "NO\n", 0;
		}
	}
	for (int i = 0; i < m; i++)
		if (abs(v[i]) > EPS)
			return cout << "NO\n", 0;
	cout << "YES\n";
	for (int i = 0; i < m; i++) {
		for (auto j : ans[i])
			cout << (int)j.first << " " << j.second << " ";
		cout << "\n";
	}
}