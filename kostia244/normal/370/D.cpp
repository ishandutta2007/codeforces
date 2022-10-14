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
int n, m, lx = INT_MAX, ly = INT_MAX, rx, ry, lst[2005], sum[2005][2005],
		lstuj[2005], cntuj[2005], wcnt = 0;
char mat[2005][2005];

int main() {
	doin();
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			cin >> mat[i][j];
			if (mat[i][j] == 'w') {
				rx = max(rx, i);
				lx = min(lx, i);
				ry = max(ry, j);
				ly = min(ly, j);
			}
		}
	int lenx = rx - lx;
	int leny = ry - ly, d;
	if (lenx > leny) {
		d = lenx - leny;
		bool c = true, D = true;
		for(int i = lx+1; i < rx; i++) {
			if(mat[i][ly] == 'w') c = false;
			if(mat[i][ry] == 'w') D = false;
		}
		if (c||((ly-1)>(m-ry)&&ry==ly)) {
			while(ly>1&&d>0)
			ly--,d--;
		}
		if (D||((ly-1)<(m-ry)&&ry==ly)) {
			while(ry<m&&d>0)
			ry++,d--;
		}
		if (d)
			return cout << -1, 0;
	}
	if (leny > lenx) {
		d = leny - lenx;
		bool c = true, D = true;
		for(int i = ly+1; i < ry; i++) {
			if(mat[lx][i] == 'w') c = false;
			if(mat[rx][i] == 'w') D = false;
		}
		if (c||((lx-1)>(n-rx)&&rx==lx)) {
			while(lx>1&&d>0)
			lx--,d--;
		}
		if (D||((lx-1)<(n-rx)&&rx==lx)) {
			while(rx<n&&d>0)
			rx++,d--;
		}
		if (d)
			return cout <<-1, 0;
	}
	lenx = rx - lx;
	leny = ry - ly;
	if(lenx != leny)
		return cout << -1, 0;
	for (int i = lx; i <= rx; i++) {
		if (mat[i][ly] == 'w' || mat[i][ly] == 'W')
			mat[i][ly] = 'W';
		else
			mat[i][ly] = '+';

		if (mat[i][ry] == 'w' || mat[i][ry] == 'W')
			mat[i][ry] = 'W';
		else
			mat[i][ry] = '+';
	}
	for (int j = ly; j <= ry; j++) {
		if (mat[lx][j] == 'w' || mat[lx][j] == 'W')
			mat[lx][j] = 'W';
		else
			mat[lx][j] = '+';

		if (mat[rx][j] == 'w' || mat[rx][j] == 'W')
			mat[rx][j] = 'W';
		else
			mat[rx][j] = '+';
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (mat[i][j] == 'w')
				return cout << -1, 0;
			else if (mat[i][j] == 'W')
				mat[i][j] = 'w';

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			cout << mat[i][j];
		cout << "\n";
	}
	return 0;
}