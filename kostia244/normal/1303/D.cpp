#pragma GCC optimize("trapv")
#pragma GCC target("avx,avx2,ssse3,sse2,sse,fma,tune=native")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<int, int>;
using vpi = vector<pair<int, int>>;
using namespace __gnu_pbds;
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
#define quit {cout << "-1\n";return;}
ll n,a,cnt[66];
void solve() {
	memset(cnt, 0, sizeof cnt);
	cin >> a >> n;
	for(int t, i = 0; i < n; i++) {
		cin >> t;
		cnt[__lg(t)]++;
	}
	int j = 0;
	ll ans = 0;
	for(int i = 0; i < 60; i++) {
		if(i==j) j++;
		if((a>>i)&1) {
			if(!cnt[i]) {
				while(j<60&&!cnt[j]) j++;
				if(j==60) quit;
				cnt[j]--;
				cnt[i] += 1ll<<(j-i);
				ans += j-i;
			}
			cnt[i]--;
		}
		cnt[i+1]+=cnt[i]/2;
	}
	cout << ans << "\n";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}