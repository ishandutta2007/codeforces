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
istream& operator>>(istream& in, pair<X, Y> a) {
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
ll n, m, diag[500][500], adiag[500][500], row[500][500], col[500][500];
vvc a;

bool valid(int i, int j) {
	return i >= 0 && i < n && j >= 0 && j < m;
}
void go_diag(ll i, ll j) {
	diag[i][j] = a[i][j] - '0';
	i--, j++;
	while (valid(i, j)) {
		diag[i][j] = (a[i][j] - '0') + diag[i + 1][j - 1];
		i--, j++;
	}
}
void go_adiag(ll i, ll j) {
	adiag[i][j] = a[i][j] - '0';
	i--, j--;
	while (valid(i, j)) {
		adiag[i][j] = (a[i][j] - '0') + adiag[i + 1][j + 1];
		i--, j--;
	}
}
void go_row(ll i, ll j) {
	row[i][j] = a[i][j] - '0';
	j++;
	while (valid(i, j)) {
		row[i][j] = (a[i][j] - '0') + row[i][j - 1];
		j++;
	}
}
void go_col(ll i, ll j) {
	col[i][j] = a[i][j] - '0';
	i++;
	while (valid(i, j)) {
		col[i][j] = (a[i][j] - '0') + col[i - 1][j];
		i++;
	}
}

ll bruteforce_vertex(int i, int j) {
	int i1, j1, i2, j2, t, ans = 0;
	i1 = i2 = i;
	j1 = j2 = j;
	while (valid(++i1, j1) && valid(++i2, ++j2)) {
		if (a[i1][j1] == '1' || a[i2][j2] == '1')
			break;
		if(row[i1][j1] == row[i2][j2]) ans++;
	}
	i1 = i2 = i;
	j1 = j2 = j;
	while (valid(++i1, j1) && valid(++i2, --j2)) {
		if (a[i1][j1] == '1' || a[i2][j2] == '1')
			break;
		if(row[i1][j1] == row[i2][j2]) ans++;
	}
	i1 = i2 = i;
	j1 = j2 = j;
	while (valid(++i1, ++j1) && valid(--i2, ++j2)) {
		if (a[i1][j1] == '1' || a[i2][j2] == '1')
			break;
		if(col[i1][j1] == col[i2][j2]) ans++;
	}
	i1 = i2 = i;
	j1 = j2 = j;
	while (valid(++i1, --j1) && valid(++i2, ++j2)) {
		if (a[i1][j1] == '1' || a[i2][j2] == '1')
			break;
		if(row[i1][j1] == row[i2][j2]) ans++;
	}
	i1 = i2 = i;
	j1 = j2 = j;
	while (valid(--i1, j1) && valid(--i2, --j2)) {
		if (a[i1][j1] == '1' || a[i2][j2] == '1')
			break;
		if(row[i1][j1] == row[i2][j2]) ans++;
	}
	i1 = i2 = i;
	j1 = j2 = j;
	while (valid(--i1, j1) && valid(--i2, ++j2)) {
		if (a[i1][j1] == '1' || a[i2][j2] == '1')
			break;
		if(row[i1][j1] == row[i2][j2]) ans++;
	}
	i1 = i2 = i;
	j1 = j2 = j;
	while (valid(--i1, ++j1) && valid(--i2, --j2)) {
		if (a[i1][j1] == '1' || a[i2][j2] == '1')
			break;
		if(row[i1][j1] == row[i2][j2]) ans++;
	}
	i1 = i2 = i;
	j1 = j2 = j;
	while (valid(--i1, --j1) && valid(++i2, --j2)) {
		if (a[i1][j1] == '1' || a[i2][j2] == '1')
			break;
		if(col[i1][j1] == col[i2][j2]) ans++;
	}
	return ans;
}

int main() {
	doin();
	cin >> n >> m;
	getv(a, n, m);
	for (ll i = 0; i < n; i++)
		go_diag(i, 0), go_adiag(i, m - 1), go_row(i, 0);
	for (ll i = 0; i < m; i++)
		go_diag(n - 1, i), go_adiag(n - 1, i), go_col(0, i);
	ll ans = 0;
	for (ll i = 0; i < n; i++)
		for (ll j = 0; j < m; j++)
			if(a[i][j] == '0')
			ans += bruteforce_vertex(i, j);
	cout << ans;
}