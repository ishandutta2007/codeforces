#define dominance 1
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
const int maxn = 2e6 + 55;//, mod = 1e9 + 7;
void solve() {
	ll n, m, c= 0, t;
	cin >> n >> m;
	for(int i = 0 ;i < n; i++) cin >> t, c+= t;
	cout << min(c, m) << '\n';
}
int main() {
	assert(dominance);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
}