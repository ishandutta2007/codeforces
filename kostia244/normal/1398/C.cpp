//#pragma GCC optimize("trapv")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
const int maxn = 3e5 + 33, mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		map<int, int> cnt;
		cnt[0]++;
		int n;cin >> n;
		string f;cin >> f;
		int cur = 0, p = 0;
		ll ans = 0;
		for(auto i : f) {i -= '0';
			p++;
			cur += i;
			ans += cnt[-cur+p];
			cnt[-cur+p]++;
		}
		cout << ans << '\n';
	}
}