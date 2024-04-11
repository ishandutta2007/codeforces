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
int n, m, sx, sy, dx[] = { 1, -1, 0, 0 }, dy[] = { 0, 0, 1, -1 }, a = 0;
char mat[5001][5001];
pi vis[2500][2500];
//mat[(n+x)%n][(m+y)%m]
void dfs(int x, int y) {
	if (mat[(1000 * n + x) % n][(1000 * m + y) % m] == 'V'
			&& vis[(1000 * n + x) % n][(1000 * m + y) % m] != pi(x, y)
			) {
		cout << "Yes";
		exit(0);
	}
	if (mat[(1000 * n + x) % n][(1000 * m + y) % m] == '#' || mat[(1000 * n + x) % n][(1000 * m + y) % m] == 'V')
		return;
	vis[(1000 * n + x) % n][(1000 * m + y) % m] = pi(x, y);
	mat[(1000 * n + x) % n][(1000 * m + y) % m] = 'V';
	for (int i = 0; i < 4; i++)
		dfs(x + dx[i], y + dy[i]);

}

int main() {
	doin();
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
			if (mat[i][j] == 'S')
				sx = i, sy = j;
		}
	dfs(sx, sy);
	cout << "No";
}