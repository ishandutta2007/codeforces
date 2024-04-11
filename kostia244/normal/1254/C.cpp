//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2,tune=native")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("trapv")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vi>;
using pi = pair<ll, ll>;
const ll mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll qry(ll t, ll i, ll j, ll k) {
	cout << t << " " << i << " " << j << " " << k << "\n";
	cout.flush();
	ll ans;cin >>ans;
	return ans;
}
int p[1010];
int main() { //DINIC ORZ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<pair<ll, ll>> h;
	p[1] = 1;
	p[2] = 2;
	for(int i = 3; i <= n; i++)
		if(qry(2, 1, p[2], i)<0)
			p[2] = i;
	for(int i = 2; i <= n; i++) {
		if(i==p[2]) continue;
		h.pb({qry(1, 1, p[2], i), i});
	}
	sort(all(h));
	int l = 3, r = n;
	for(auto i : h) {
		if(i!=h.back()) {
			if(qry(2, 1, h.back().second, i.second)<0)
				p[l++]=i.second;
			else
				p[r--]=i.second;
		} else
			p[r] = i.second;
	}
	cout << "0 ";
	for(int i = 1; i <= n; i++) cout << p[i] << " ";
}