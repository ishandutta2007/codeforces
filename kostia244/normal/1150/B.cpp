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
typedef int _I;
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
vvc a;

bool can1(int i, int j) {
	if (i > 0 && i + 1 < n && j + 2 < n)
		return a[i][j] == '.' && a[i][j + 1] == '.' && a[i][j + 2] == '.'
				&& a[i + 1][j + 1] == '.' && a[i - 1][j + 1] == '.';
	return false;
}
bool can2(int i, int j) {
	if (i + 2 < n && j + 1 < n && j > 0)
		return a[i][j] == '.' && a[i + 1][j] == '.' && a[i + 2][j] == '.'
				&& a[i + 1][j + 1] == '.' && a[i + 1][j - 1] == '.';
	return false;
}
void do1(int i, int j) {
	a[i][j] = '#', a[i][j + 1] = '#', a[i][j + 2] = '#', a[i + 1][j + 1] = '#', a[i - 1][j + 1] = '#';
}
void do2(int i, int j) {
	a[i][j] = '#', a[i + 1][j] = '#', a[i + 2][j] = '#', a[i + 1][j + 1] = '#', a[i
			+ 1][j - 1] = '#';

}
int main() {
	doin();
	cin >> n;
	a.resize(n);
	for (auto& i : a)
		getv(i, n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if(a[i][j] == '#')
				continue;
			if (can1(i, j))
				do1(i, j);
			else if (can2(i, j))
				do2(i, j);
			else {
				cout << "NO";
				exit(0);
			}
		}
	}
	cout << "YES";
}