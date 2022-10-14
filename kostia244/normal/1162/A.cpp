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
//		freopen("in", "r", stdin);
//		freopen("out", "w", stdout);
#endif//1
}
template<typename T>
void getv(T& a, int n) {
	a.resize(n);
	for (auto& i : a)
		cin >> i;
}
typedef long long ll;
typedef double ld;
typedef int _I;
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
int n, h, m, l, r, c, ans = 0;
int main() {
	doin();
	cin >> n >> h >> m;
	vi mh(n, h);
	while(m--) {
		cin >> l >> r >> c;
		for(l--; l < r; l++)
			mh[l] = min(mh[l], c);
	}
	for(auto& i : mh)
		ans += i*i;
	cout << ans;

}