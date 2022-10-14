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
const int maxn = 1e5 + 33, mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll t, cnt[60];
void solve() {
	int n, k;
	memset(cnt, 0, sizeof cnt);
	vi a;
	cin >> n >> k;
	a.resize(n);
	for(auto &i : a) cin >> i;
	for(auto i : a) {
		int t = 0;
		while(i) {
			cnt[t]+=i%k;
			i/=k;
			t++;
		}
	}
	int ok = 1;
	for(int i = 0; i < 60; i++) {
		if(cnt[i]>1) ok = false;
	}
	cout << (ok?"Yes":"No") << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--) solve();
}