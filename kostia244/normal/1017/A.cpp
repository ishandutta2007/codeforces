#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
const int maxn = 1<<21, mod = 1e9 + 7;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vi a(n);
	for(int t, i = 0; i < n; i++) {
		for(int j = 0;j  < 4; j++) cin >> t, a[i] += t;
		
	}
	int ans = 1;
	for(int i = 1; i < n; i++) ans +=a[i] > a[0];
	cout << ans;
}