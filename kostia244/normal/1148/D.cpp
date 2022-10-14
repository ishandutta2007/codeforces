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
int n, pos[300100], ta, tb;
__V<pair<pi, int>> a, b;

int main() {
	doin();
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ta >> tb;
		if (ta > tb)
			b.pb( { { ta, tb }, i });
		else
			a.pb( { { ta, tb }, i });
	}
	//1<2
	sort(all(a), [](const pair<pi, int>& a, const pair<pi, int>& b) {
		bool A = a.first.second>b.first.second;
		bool B = b.first.second>a.first.second;
		if(A&&B)
			return a.first.first<b.first.first;
		if(A)
			return true;
		return false;
	});
	//2>1
	sort(all(b), [](const pair<pi, int>& a, const pair<pi, int>& b) {
		bool A = a.first.second<b.first.second;
		bool B = b.first.second<a.first.second;
		if(A&&B)
			return a.first.first>b.first.first;
		if(A)
			return true;
		return false;
	});
	if(a.size() < b.size())
		a = b;
	cout << a.size() << "\n";
	for(auto i : a)
		cout << i.second+1 << " ";
}