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
ll n, t, i, j, k, mat[501][501], ans;
vi x, out;
int main() {
	doin();
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> mat[i][j];
	x.resize(n);
	for (auto& i : x)
		cin >> i;
	reverse(all(x));
	for (int kt = 0; kt < n; kt++) {
		k = x[kt];
		for (int it = 0; it < n; it++) {
			i = x[it];
			for (int jt = 0; jt < n; jt++) {
				j = x[jt];
				if(it < kt && jt < kt)
					ans -= mat[i][j];
				t = mat[i][k] + mat[k][j];
				if(t < mat[i][j])
					mat[i][j] = t;
				if(it <= kt && jt <= kt)
					ans += mat[i][j];
			}
		}
		out.pb(ans);
	}
	cout << fixed;
	copy(rall(out), oit<ll>(cout, " "));
	return 0;
}