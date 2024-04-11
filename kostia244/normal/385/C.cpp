#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define __V vector
#define vi __V<ll>
#define pi pair<ll, ll>
#define mod 1000000007ll
using namespace std;
int n, m, l, r, t, lp[10000007], pref[10000007];
vi pr;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for (int i = 2; i <= 10000000; i++) {
		if (lp[i] == 0)
			lp[i] = i, pr.pb(i);
		for(int j = 0; j < pr.size() && pr[j] <= lp[i] && (i * 1ll * pr[j]) <= 10000000ll; j++)
			lp[i * pr[j]] = pr[j];
	}
	cin >> n;
	while(n--) {
		cin >> t;
		for(; t != 1; pref[lp[t]]+=(lp[t] != lp[t/lp[t]]), t /= lp[t]);
	}
	for(int i = 1; i <= 10000000; i++)
		pref[i] += pref[i - 1];
	cin >> m;
	while(m--) {
		cin >> l >> r;
		if(l > 10000000) cout << "0\n";
		else {
			r = min(10000000, r);
			cout << pref[r]-pref[l-1] << "\n";
		}
	}
}