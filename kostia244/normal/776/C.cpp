#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define __V vector
#define vi __V<ll>
#define pi pair<int, int>
#define all(x) x.begin(), x.end()
#define mod 1000000007ll

using namespace __gnu_pbds;
using namespace std;
ll n, k, t, kpow, pref = 0, ans = 0;
map<ll, int> cnt;
int main() {
	cin.tie();
	cout.tie();
	ios::sync_with_stdio(0);
	cin >> n >> k;
	cnt[0]++;
	for (int i = 0; i < n; i++) {
		cin >> t;
		pref += t;
		t = 1;
		if (k == 1)
			ans += cnt[pref - 1];
		else if (k == -1)
			ans += cnt[pref + 1], ans += cnt[pref - 1];
		else
			for (int i = 0; i < 100 && llabs(t) <= 1000000000000000ll; i++, t *=
					k)
				ans += cnt[pref - t];

		cnt[pref]++;
	}
	cout << ans;
}