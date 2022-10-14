#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4")
#include <bits/stdc++.h>
#define int long long
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
const int maxn = 1<<18, mod = 1e9 + 7;
int p[maxn];
int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	p[0] = 1;
	for(int i = 1; i < maxn; i++) p[i] = p[i-1]*10ll%mod;
	for(int i = 1; i < maxn; i++) p[i] = (p[i] + p[i-1])%mod;
	string n;
	cin >> n;
	int ans = 0, cur = 0;
	for(int i = 0; i+1 < n.size(); i++) {
		cur = (cur*10ll + (n[i]-'0'))%mod;
		ans = (ans + cur*1ll*p[n.size()-i-2])%mod;
	}
	reverse(all(n));
	cur = 0;
	int pw = 1;
	for(int i = 0; i+1 < n.size(); i++) {
		cur = (cur + pw*1ll*(n[i]-'0'))%mod;
		pw = pw*10ll%mod;
		ans = (ans + cur*1ll*(n.size()-i-1))%mod;
	}
	cout << ans << endl;
}