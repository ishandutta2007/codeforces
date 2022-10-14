//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2,tune=native")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("trapv")
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pi = pair<ll, ll>;
const int mod = 1000000007;
const ll inf = 1e18;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, m, sz1, sz2;
string s[20];
map<vector<int>, int> cnt;
int main() { //DINIC ORZ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	vi a;
	sz1=n/2, sz2=n-sz1;
	a.resize(m);
	for(int i = 0; i < m; i++)
		cin >> s[i] >> a[i];
//	for(int i = 0; i < m;i++) cout << s[i] << "\n";
	for(ll msk = 0; msk < 1<<sz1; msk++) {
		vi t(m);
		for(int j = 0; j < m; j++)
		for(int i = 0; i < sz1; i++) {
			t[j] +=(s[j][i]-'0')==((msk>>i)&1);
		}
		cnt[t]++;
	}
	ll ans = 0;
	for(ll msk = 0; msk < 1<<sz2; msk++) {
		vi t = a;
		for(int j = 0; j < m; j++)
		for(int i = 0; i < sz2; i++) {
			t[j] -= (s[j][sz1+i]-'0')==((msk>>i)&1);
		}
		ans += cnt[t];
	}
	cout << ans;
}