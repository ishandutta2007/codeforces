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
const int mod = 7 * 17 * (1 << 23) + 1;
const ll inf = 1e18;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
	int n;
	cin >> n;
	vector<string> s;
	s.resize(n);
	set<char> q;
	for(auto &i : s) cin >> i, q.insert(i[0]);
	char t = '0';
	int ans = 0;
	for(int i = 0; i < n; i++) {
		for(int j = i+1; j < n; j++) {
			if(s[i]==s[j]) {
				while(q.count(t)) t++;
				s[j][0] = t;
				ans++;
				q.insert(t);
			}
		}
	}
	cout << ans << "\n";
	for(auto i : s) cout << i << "\n";
}
int main() { //DINIC ORZ, FFT ORZ
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
}