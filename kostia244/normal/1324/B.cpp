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
const int maxn = 125, mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
	int n, t;
	cin >> n;
	map<int, int> cnt;
	vi a;
	a.resize(n);
	for(auto &i : a) cin >> i;
	cnt[a[0]]++;
	for(int i = 2; i < n; i++) {
		if(cnt[a[i]]) {
			cout << "YES\n";
			return;
		}
		cnt[a[i-1]]++;
	}
	cout << "NO\n";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
}