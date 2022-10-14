#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<ll>;
const ll mod = 998244353ll;
vi hv[200200];
int cur = 0, cnt[200200], si=0, ei=0;

int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vi a;
	a.resize(m);
	for (auto &i : a)
		cin >> i;
	vi sts, ens;
	ll norm = 0;
	for (int i = 1; i < m; i++) {
		norm += abs(a[i] - a[i - 1]);
		if (a[i] != a[i - 1]) {
			hv[a[i - 1]].pb(a[i]);
			hv[a[i]].pb(a[i - 1]);
			sts.pb(min(a[i - 1], a[i]));
			ens.pb(max(a[i - 1], a[i]));
		}
	}
	sort(all(sts));
	sort(all(ens));
	for(int i = 1; i <= n; i++) {
		while(si<sts.size()&&sts[si]==i) si++, cur++;
		cnt[i] = cur;
//		cout << cur << " ";
		while(ei<ens.size()&&ens[ei]==i) ei++, cur--;
	}
//	cout << norm << " ";
	for(int i = 1; i <= n; i++) {
		ll ans = norm;
		for(auto j : hv[i]) ans -= abs(i-j), ans += j - (j>i);//, cout << j << " ";
		ans -= cnt[i] - hv[i].size();
		cout << ans << " ";
//		cout << "\n";
//		cout <<cnt[i] + hv[i].size()<< " ";
	}

}