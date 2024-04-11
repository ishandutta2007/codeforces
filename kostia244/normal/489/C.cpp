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
int s, m, ts;

int main() {
	doin();
	cin >> m >> s;
	if(s == 0 && m == 1)
		return cout << "0 0\n", 0;
	if (9 * m < s || s == 0)
		return cout << "-1 -1", 0;
	vi mn;
	ts = s;
	mn = vi(m, 0);
	for (int i = 0; i < m; i++) {
		for(int k = 0+(i==0); k < 10; k++)
		if((ts-k) <= (m-i-1)*9){
			mn[i] = k, ts-=k;
			break;
		}
	}
	for (auto i : mn)
		cout << i;
	cout << " ";
	ts = s;
	mn = vi(m, 0);
	for (int i = 0; ts; i++) {
		if (ts < 9)
			mn[i] += ts, ts = 0;
		else
			mn[i] = 9, ts -= 9;
	}
	for (auto i : mn)
		cout << i;
}