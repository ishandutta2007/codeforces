#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define xx first.first
#define yy first.second
#define __V vector
#define all(x) x.begin(), x.end()
#define mod 998244353ll
//using namespace __gnu_pbds;
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
typedef __V <ll> vi;
typedef __V <pi> vpi;
typedef __V <__V<int>> vvi;
typedef __V <__V<pi>> vvpi;

int n, m, k, ans = 0;
vi s, p, c, smx;
int main() {
	doin();
	cin >> n >> m >> k;
	p.resize(n);
	for(auto& i : p) cin >> i;
	s.resize(n);
	for(auto& i : s) cin >> i;
	c.resize(k);
	for(auto& i : c) cin >> i;
	smx.resize(m + 1, 0);
	for(int i = 0; i < n; i++) {
		if(smx[s[i]] < p[i])
			smx[s[i]] = p[i];
	}
	for(auto& i : c) {
		if(smx[s[i-1]] != p[i-1])
			ans++;
	}
	cout << ans;
}