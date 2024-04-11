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
string s, t, k;
int pw[100005], shash[100005], thash[100005];
int i, mn, n, ans;
bool eq(int is, int js, int it, int jt) {
	return ((shash[js] - (is ? shash[is - 1] : 0)) * pw[n - is])
			== ((thash[jt] - (it ? thash[it - 1] : 0)) * pw[n - it]);
}
bool div(int k) {
	if (s.size() % k)
		return false;
	for (int i = 0; i + k <= s.size(); i += k)
		if (!eq(i, i + k - 1, 0, k - 1))
			return false;
	return true;
}
int main() {
	doin();
	cin >> s >> t, mn = min(s.size(), t.size()), n = max(s.size(), t.size());
	if(s.size() < t.size())
		swap(s, t);
	i = 0;
	while (i < mn && s[i] == t[i])
		i++;
	while (i > 0 && ((s.size() % i) || (t.size() % i)))
		i--;
	pw[0] = 1;
	for (int i = 1; i <= n; i++)
		pw[i] = pw[i - 1] * p;
	shash[0] = s[0];
	for (int i = 1; i < s.size(); i++)
		shash[i] = shash[i - 1] + (pw[i] * s[i]);
	thash[0] = t[0];
	for (int i = 1; i < t.size(); i++)
		thash[i] = thash[i - 1] + (pw[i] * t[i]);
	for(int d = 1; d*d <= i; d++) {
		if(i%d) continue;
		ans += div(d);
		if(d != (i/d))
			ans += div(i/d);
	}
	cout << ans;
	return 0;
}