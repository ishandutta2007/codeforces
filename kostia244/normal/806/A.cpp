//#pragma GCC optimize("trapv")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
const int maxn = 5e2 + 3, mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll x, y, p, q;
void solve() {
	cin >> x >> y >> p >> q;
	if(p==q) {
		if(x==y) {cout << "0\n"; return;}
		cout << "-1\n";
		return;
	}
	if(p==0) {
		if(x==0) {cout << "0\n"; return;}
		cout << "-1\n";
		return;
	}
	ll k = max({(y+q-1)/q, (x+p-1)/p, (y-x+q-p-1)/(q-p)});
	cout <<k*q-y << "\n";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
}