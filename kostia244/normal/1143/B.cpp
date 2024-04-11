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
#define mod 998244353ll
using namespace __gnu_pbds;
using namespace std;
void doin() {
	cin.tie();
	cout.tie();
	ios::sync_with_stdio(0);
//#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//#endif
}
typedef long long ll;
typedef double ld;
typedef pair<ll, ll> pi;
typedef pair<ld, ld> pd;
typedef map<int, int> mii;
typedef __V <int> vi;
typedef __V <pi> vpi;
typedef __V <__V<int>> vvi;
typedef __V <__V<pi>> vvpi;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll ans = 0, p = 1;
string s;
int pw[11];
int main() {
	doin();
	cin >> s;
	pw[0] = 1;
	for(int i = 1; i < 11; i++) pw[i] = 9*pw[i-1];
	for(int i = 0; i < s.size(); i++) {
		ans = max({ans, p*(s[i] != '1' ? (s[i]-'0'-1) : 1)*pw[s.size()-i-1]});
		p *= (s[i]-'0');
	}
	ans = max(ans, p);
	cout << fixed << ans;
}