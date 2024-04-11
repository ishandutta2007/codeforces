#pragma GCC optimize("trapv")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<int>;
const int maxn = 1<<19, rt = 1<<10, mod = 1e9 + 7;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	int ans = 1<<30;
	while(m--) {
		int l, r; cin >> l >> r;
		ans = min(ans, r-l+1);
	}
	cout << ans << '\n';
	for(int i = 0; i < n; i++) {
		cout << (i%ans) << " ";
	}
}