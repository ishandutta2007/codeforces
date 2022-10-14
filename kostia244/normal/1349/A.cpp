#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
const int maxn = 1<<18, mod = 1e9 + 7;
#define div dsaklfjasd
ll n, ans = 1;
vi div[maxn];
void factor(int v) {
	for(int d = 2; d*d <= v; d++) {
		if(v%d) continue;
		int p = 0;
		while(v%d == 0) v/=d, p++;
		div[d].pb(p);
	}
	if(v > 1) div[v].pb(1);
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for(int t, i = 0; i < n; i++) {
		cin >> t;
		factor(t);
	}
	for(ll i = 1; i < maxn; i++) {
		sort(all(div[i]));
		if(div[i].size() == n) ans *= pow(i, div[i][1]);
		if(div[i].size() == n-1) ans *= pow(i, div[i][0]);
	}
	cout << ans;
}