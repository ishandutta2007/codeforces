#include<bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
const ll mod = 7 * 17 * (1 << 23) + 1;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, cnt[2];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	vi b;
	for(int t, i = 0; i < n; i++) {
		cin >> t;
		cnt[t&1]++;
		b.pb(t);
	}
	if(cnt[0]&&cnt[1]) sort(all(b));
	for(auto i : b) cout << i << " ";
	return 0;
}