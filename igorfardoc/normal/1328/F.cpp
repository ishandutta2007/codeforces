#include<bits/stdc++.h>
#define INF 1000000000000000000ll
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;



int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    int n, k;
    cin >> n >> k;
    vi a(n);
    for(int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll ans = INF;
    vector<ll> pref(n + 1, 0);
    for(int i = 1; i <= n; i++) {
    	pref[i] = pref[i - 1] + a[i - 1];
    }
    for(int i = 0; i < n; i++) {
    	int here = a[i];
    	int lower1 = lower_bound(a.begin(), a.end(), a[i]) - a.begin();
    	int upper1 = upper_bound(a.begin(), a.end(), a[i]) - a.begin();
    	if(upper1 - lower1 >= k) {
    		ans = 0;
    		break;
    	}
    	int need = k - (upper1 - lower1);
    	if(lower1 >= need) {
    		ans = min(ans, (ll)(a[i] - 1) * lower1 - pref[lower1] + need);
    	} else {
    		int need1 = need - lower1;
    		ll ans1 = (ll)a[i] * lower1 - pref[lower1];
    		ans1 += pref[n] - pref[upper1] - (ll)(a[i] + 1) * (n - upper1) + need1;
    		ans = min(ans, ans1);
    	}
    	if(n - upper1 >= need) {
    		ans = min(ans, pref[n] - pref[upper1] - (ll)(a[i] + 1) * (n - upper1) + need);
    	} else {
    		int need1 = need - (n - upper1);
    		ll ans1 = pref[n] - pref[upper1] - (ll)(a[i]) * (n - upper1);
    		ans1 += (ll)(a[i] - 1) * lower1 - pref[lower1] + need1;
    		ans = min(ans, ans1);
    	}
    }
    cout << ans << '\n';
}