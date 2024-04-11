#pragma GCC optimize("trapv")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
using ld = long double;
const int maxn = 1e5 + 555;
using namespace __gnu_pbds;
vi pos[26];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	ll ans = 0;
	for(int i = 0; i < s.size(); i++) {
		pos[s[i]-'a'].pb(i);
		ans = max(ans, (ll)pos[s[i]-'a'].size());
	}
	for(int i = 0; i < 26; i++) {
		for(int j = 0; j < 26; j++) {
			int p = 0;
			ll t = 0;
			for(auto k : pos[i]) {
				while(p < pos[j].size() && pos[j][p] < k) p++;
				t += p;
			}
			ans = max(ans, t);
		}
	}
	cout << ans;
	return 0;
}