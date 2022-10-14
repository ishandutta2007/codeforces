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
int n, m, cnt[500001], cnt2[500001];
map<pi, int> dup;
string s, t;
vpi v;

bool d(pi a, pi b) {
	return ((a.first == b.first || a.second == b.second)
			|| (a.first == b.second || a.second == b.first));
}

int main() {
	doin();
	cin >> n >> m;
	v.resize(m);
	for (auto& i : v) {
		cin >> i.first >> i.second;
		++cnt[i.first];
		++cnt[i.second];
		dup[i]++;
	}
	int i = 0;
	while (i < m && d(v[0], v[i]))
		i++;
	if (i == m)
		return cout << "YES", 0;
	vi f = { v[0].first, v[0].second, v[i].first, v[i].second };
	for (int i = 0; i < 4; i++)
		for (int j = i + 1; j < 4; j++) {
			if (cnt[f[i]] + cnt[f[j]] - dup[mp(f[i], f[j])] >= m)
				return cout << "YES", 0;
		}
	cout << "NO";
}