#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4,sse4.1")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
#define apply fuckstl
#define int long long
using namespace std;
using ll = int64_t;
const int maxn = 303, mod = 1000000007;
int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	ll tc;
	cin >> tc;
	while(tc--) {
		int n;cin >> n;
		string s;cin >> s;
		int a = count(all(s), '<'), b = count(all(s), '>');
		if(min(a, b) == 0) {
			cout << s.size() << '\n';
			continue;
		}
		int ans = 0;
		for(int i = 0; i < s.size(); i++) {
			int nxt = (i+1)%s.size();
			ans += s[i] == '-' || s[nxt] == '-';
		}
		cout << ans << '\n';
	}
}