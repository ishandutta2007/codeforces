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
int n, m;

void handleSpecial1() {
	if (n == 1 && m == 2) {
		cout << "0\n";
		cout << "1 1\n";
		cout << "1 2\n";
		cout << "1 1\n";
		exit(0);
	}
	if (n == 2 && m == 1) {
		cout << "0\n";
		cout << "1 1\n";
		cout << "2 1\n";
		cout << "1 1\n";
		exit(0);
	}
	if (n == 1) {
		cout << "1\n";
		cout << "1 " << m << " 1 1\n";
		for (int i = 1; i <= m; i++)
			cout << "1 " << i << "\n";
		cout << "1 1\n";
		exit(0);
	}
	if (m == 1) {
		cout << "1\n";
		cout << n << " 1 1 1\n";
		for (int i = 1; i <= n; i++)
			cout << i << " 1\n";
		cout << "1 1\n";
		exit(0);
	}
}

void solveN() {
	cout << "0\n";
	for (int x = 0; x < n; x += 2) {
		for (int y = 1 + (x != 0); y <= m; y++)
			cout << (x + 1) << " " << y << "\n";
		for (int y = m; y > 1; y--)
			cout << (x + 2) << " " << y << "\n";
	}
	for (int x = n; x; x--)
		cout << x << " 1\n";
}
void solveM() {
	swap(n, m);
	cout << "0\n";
	for (int x = 0; x < n; x += 2) {
		for (int y = 1 + (x != 0); y <= m; y++)
			cout << y << " " << (x + 1) << "\n";
		for (int y = m; y > 1; y--)
			cout << y << " " << (x + 2) << "\n";
	}
	for (int x = n; x; x--)
		cout << "1 " << x << "\n";
}

void solveOdd() {
	cout << "1\n";
	cout << n << " " << m << " 1 1\n";
	for (int x = 0; x+1 < n; x += 2) {
		for (int y = 1; y <= m; y++)
			cout << (x + 1) << " " << y << "\n";
		for (int y = m; y; y--)
			cout << (x + 2) << " " << y << "\n";
	}
	for (int y = 1; y <= m; y++)
		cout << n << " " << y << "\n";
	cout << "1 1\n";
}

int main() {
	doin();
	cin >> n >> m;
	handleSpecial1();
	if ((n & 1) == 0)
		solveN();
	else if ((m&1) == 0)
		solveM();
	else
		solveOdd();
}