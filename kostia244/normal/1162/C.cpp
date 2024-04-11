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
#endif
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
int n, k, t, cnt[100007], lst[100007], fst[100007], ans;
int main() {
	doin();
	cin >> k >> n;
	for (int i = 0; i <= k; i++)
		fst[i] = -1, lst[i] = -1;
	for (int i = 1; i <= n; i++) {
		cin >> t, lst[t] = i, cnt[t]++;
		if(fst[t] == -1)
			fst[t] = i;
	}
	for (int i = 1; i <= k; i++) {
		if (cnt[i] == 0)
			ans++;
		if (i > 1 && (fst[i] >= lst[i - 1] || !cnt[i]))
			ans++;
		if (i < k && (fst[i] >= lst[i + 1] || !cnt[i]))
			ans++;
	}
	cout << ans;
}