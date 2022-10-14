#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
const int maxn = 1<<18;
ll n, m, T = 0, sum = 0, a[maxn];
vector<ll> f[maxn];
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		cin >> a[i];
	}
	for(int i = 2; i <= m; i++) {
		if(a[i] == a[i-1]) continue;
		f[a[i]].push_back(a[i-1]);
		f[a[i-1]].push_back(a[i]);
		sum += abs(a[i]-a[i-1]);
	}
	for(int i = 1; i <= n; i++) {
		if(f[i].empty()) continue;
		sort(all(f[i]));
		ll x = 0, med = f[i][f[i].size()/2];
		for(auto j : f[i]) {
			x -= abs(j-i);
			x += abs(j-med);
		}
		T = min(T, x);
	}
	cout << sum + T << endl;
	return 0;
}