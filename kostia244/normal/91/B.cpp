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
//  freopen("input.txt", "r", stdin);
#endif
}
typedef long long ll;
typedef ll _I;
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
const int N = 1e5 + 5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n;
vi a, mn, ans;
int main() {
	doin();
	cin >> n;
	a.resize(n);
	mn.resize(n);
	ans.resize(n, -1);
	for (auto& i : a)
		cin >> i;
	reverse(all(a));
	mn[0] = a[0];
	for (int i = 1; i < n; i++)
		mn[i] = min(mn[i - 1], a[i]);
	for (int i = 1; i < n; i++) {
		auto it = lower_bound(mn.begin(), mn.begin()+i, a[i]-1, greater<int>());
		ans[i] = it != mn.end() ? (mn.begin()+i-it-1) : -1;
	}
	reverse(all(ans));
	for (auto& i : ans)
		cout << i << " ";
}