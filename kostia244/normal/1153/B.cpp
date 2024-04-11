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
int n, m, h;
vi a, b;
vvi t;

int main() {
	doin();
	cin >> n >> m >> h;
	a.resize(m);
	for (auto& i : a)
		cin >> i;
	b.resize(n);
	for (auto& i : b)
		cin >> i;
	t.resize(n, vi(m));
	for (auto& i : t)
		for (auto& j : i)
			cin >> j;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if(t[i][j]) {
				cout << min(b[i], a[j]) << " ";
			}else
				cout <<0 << " ";
		}
		cout << "\n";
	}

	return 0;
}