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
typedef double ld;
typedef pair<ll, ll> pi;
typedef pair<ld, ld> pd;
typedef map<int, int> mii;
typedef __V <ll> vi;
typedef __V <pi> vpi;
typedef __V <__V<int>> vvi;
typedef __V <__V<pi>> vvpi;
const int p = 37;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll ans, n, M = 0, mx[2000005];
vi a;
int main() {
	doin();
	cin >> n;
	a.resize(n);
	for(int i = 0; i < n; i++)
		cin >> a[i], M = max(M, a[i]), mx[a[i]+1] = a[i];
	M<<=1;
	for(int i = 1; i <= M; i++)
		mx[i] = max(mx[i], mx[i-1]);
	sort(all(a));
	a.erase(unique(all(a)), a.end());
	n = a.size();
	for(int i = 0; i < n; i++) {
		for(int j = 2*a[i]; j <= M; j+=a[i]) {
			ans = max(ans, mx[j]%a[i]);
		}
	}
	cout << ans;
	return 0;
}