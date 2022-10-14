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
int n, pos[300100];
vi a;
vpi ans;
void doswap(int i, int j) {
	swap(a[i], a[j]);
	swap(pos[a[i]], pos[a[j]]);
	if(2*abs(i-j) >= n) {
		ans.pb({i+1, j+1});
		return;
	}
	if((i < n/2) == (j < n/2)) {
		int buff = (i < n/2) ? n-1 : 0;
		ans.pb({buff+1, i+1});
		ans.pb({buff+1, j+1});
		ans.pb({buff+1, i+1});
	} else {
		if(i > j)
			swap(i, j);
		ans.pb({i+1, n});
		ans.pb({1, j+1});
		ans.pb({1, n});
		ans.pb({i+1, n});
		ans.pb({1, j+1});
	}
}
int main() {
	doin();
	cin >> n;
	a.resize(n);
	for (auto& i : a)
		cin >> i;
	for(int i = 0; i < a.size(); i++)
		pos[a[i]] = i;
	for(int i = 0; i < n; i++) {
		if(i+1 != a[i]) {
			doswap(i, pos[i+1]);
		}
	}
	cout << ans.size() << "\n";
	for(auto i : ans) cout << i.first << " " << i.second << "\n";
}