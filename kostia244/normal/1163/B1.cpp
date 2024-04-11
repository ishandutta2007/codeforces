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
#define mod 1234567891ll
using namespace __gnu_pbds;
using namespace std;
void doin() {
	cin.tie();
	cout.tie();
	ios::sync_with_stdio(0);
#ifdef LOCAL
//		freopen("in", "r", stdin);
//		freopen("out", "w", stdout);
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
int n, m, t, dp[100005], difval = 1, ans = 0;
vi a;
map<int, int> cnt;

int main() {
	cin >> n;
	memset(dp, 0, sizeof dp);
	getv(a, n);
	dp[a[0]]++;
	cnt[1]++;
	for (int i = 1; i < n; i++) {
		if (--cnt[dp[a[i]]] <= 0)
			cnt.erase(dp[a[i]]);
		dp[a[i]]++;
		++cnt[dp[a[i]]];
		if(cnt.size() == 1 && (cnt.begin()->second == 1 || cnt.begin()->first == 1))
			ans = i;
		if(cnt.size() == 2) {
			auto a = cnt.begin();
			auto b = a;
			b++;
			if(a->first - b->first == 1 && a->second == 1)
				ans = i;
			if(b->first - a->first == 1 && b->second == 1)
				ans = i;
			if(a->first == 1 && a->second == 1)
				ans = i;
			if(b->first == 1 && b->second == 1)
				ans = i;

		}
	}
	cout << ans + 1;
}