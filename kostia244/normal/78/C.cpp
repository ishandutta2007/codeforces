//#pragma GCC optimize("trapv")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
const int maxn = 1e3 + 5;
ll n, m, k;
vi divs;
int s[maxn], b[maxn];
#define dp (l<maxn?s[l]:b[m/l])
int go(int l) {
	if(dp!=-1) return dp;
	dp=0;
	for(auto d : divs) {
//		cout << d << " " << (d==l) << bool(l%d) << (d<k) << "\n";
		if(d>=l||l%d||d<k) continue;
		if((l/d)&1) {dp=1;break;}
		dp|=go(d)^1;
		if(dp) break;
	}
//	cout << l << " " << dp << "\n";
	return dp;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(s, -1, sizeof s);
	memset(b, -1, sizeof b);
	cin >> n >> m >> k;
	for(ll d = 1; d*d <= m; d++) {
		if(m%d) continue;
		divs.pb(d);
		if(d*d!=m)
			divs.pb(m/d);
	}
	if(n&1) {
		if(go(m))
			cout << "Timur";
		else
			cout << "Marsel";
	} else
		cout << "Marsel";
}