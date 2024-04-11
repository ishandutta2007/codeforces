#include <algorithm>
#include <chrono>
#include <iostream>
#include <bits/stdc++.h>
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int q, t, ans;

int main() {
	doin();
	cin >> q;
	while(q--) {
		cin >> t;
		ans = 0;
		t++;
		if(t != (t&(-t))) {
			t--;
			while(t)
				t>>=1, ans++;
			ans = (1<<ans)-1;
		} else {
			t--;
			ans = 1;
			for(int d = 2; d*d <= t; d++) {
				if(t%d) continue;
				ans = max(ans, t/d);
				ans = max(ans, d);
			}
		}
		cout << fixed << ans << "\n";
	}
	return 0;
}