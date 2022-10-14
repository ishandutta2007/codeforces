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
const ll mod = 7 * 17 * (1 << 23) + 1;
const ll inf = 1e18;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
	int n, k;
	string s, t;
	cin >> n >> k >> s;
	for(int i = 1; i < k; i++) {
		t += "()";
	}
	int u = (n-t.size())/2;
	for(int i = 0; i < u; i++) t+="(";
	for(int i = 0; i < u; i++) t+=")";
	vector<pi> op;
	for(int i = 0; i < n; i++) {
		if(s[i]==t[i]) continue;
		int j = i;
		while(s[j]==s[i]) j++;
		op.pb({i+1, j+1});
		reverse(s.begin()+i, s.begin()+j+1);
	}
	cout << op.size() << "\n";
	for(auto i : op) cout << i.first << " " << i.second << "\n";
}
int main() { //DINIC ORZ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
}