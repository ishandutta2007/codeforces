//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2,tune=native")
//#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("trapv")
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using pi = pair<ll, ll>;
const int mod = 7*17*(1<<23) + 1;
const ll inf = 1e18;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
	vi a;
	int n;
	cin >> n;
	int t, p = -1, cnt = 0, i = 0;
	for(; i < n; i++) {
		cin >> t;
		if(p==t) cnt++;
		else {
			if(cnt) a.pb(cnt);
			cnt = 1;
		}
		p = t;
	}
	if(cnt) a.pb(cnt);
	ll ans = 0;
	cnt = 0;
	i=0;
//	for(auto i : a) cout << i << " ";
	int g, s, b;
	g=s=b=0;
	int gg, ss, bb;
	gg=ss=bb=0;
	vi sm;
	int si = 0;
	while(i<a.size()&&2*(a[i] + (sm.empty()?0:sm.back()))<=n) {
		sm.pb(a[i] + (sm.empty()?0:sm.back()));
		if(sm.size()>2) {
			while(si+1 < sm.size()&&abs((sm[si+1]-sm[0])-(sm.back()-sm[si+1]))<abs((sm[si]-sm[0])-(sm.back()-sm[si]))) si++;
			g = sm[0];
			s = sm[si]-sm[0];
			b = sm.back()-sm[si];
			if(2*(g+s+b)<=n&&g&&s&&b&&g<s&&g<b) gg=g,ss=s,bb=b;
//			cout << g << " " << s << " " << b << "\n";
		}
		i++;
	}
	cout << gg << " " << ss << " " << bb << "\n";
}
int main() { //DINIC ORZ, FFT ORZ
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
}