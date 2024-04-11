#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
const int maxn = 1<<17, mod = 1e9 + 7;
void solve() {
	ll a, b, t;
	cin >> a >> b;
	cout << min({a, b, (a+b)/3}) << '\n';
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}