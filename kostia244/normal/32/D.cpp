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
#ifdef LOCALc
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
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
typedef int _I;
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
int n, m, k, num = 0, li, lj, lr;
char mat[400][400];
bool star(int r, int i, int j) {
	return mat[i][j] == '*' && mat[i][j] == mat[i + r][j]
			&& mat[i][j] == mat[i - r][j] && mat[i][j] == mat[i][j + r]
			&& mat[i][j] == mat[i][j - r];
}
int main() {
	doin();
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> mat[i][j];
	for (int r = 1; num < k && r <= min(n - 1, m - 1) / 2; r++)
		for (int i = r; num < k && i + r < n; i++)
			for (int j = r; num < k && j + r < m; j++) {
				if (star(r, i, j))
					li = i, lj = j, lr = r, num++;
			}
	if (num < k)
		cout << -1;
	else {
		cout << li + 1 << " " << lj + 1 << "\n";
		cout << li + 1 - lr << " " << lj + 1 << "\n";
		cout << li + 1 + lr << " " << lj + 1 << "\n";
		cout << li + 1 << " " << lj + 1 - lr << "\n";
		cout << li + 1 << " " << lj + 1 + lr << "\n";
	}
}