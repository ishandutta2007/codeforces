#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
const int maxn = 1<<19, mod = 1e9 + 7;
ll dfs(ll a, ll b) {
	if(a == 1 || b == 1) return max(a, b);
	return (a/b)+dfs(b, a%b);
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	ll a, b;
	cin >> a >> b;
	cout << dfs(a, b) << endl;
}