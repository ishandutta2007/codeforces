#include<bits/stdc++.h>
#define left left1
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
vvi pos(20);
vector<vector<ll>> pref(20);
vector<vector<ll>> left(20, vector<ll>(20));
int n;

ll get_sum(int l, int r) {
	if(l > r) {
		return 0;
	}
	ll ans = (ll)r * (r + 1) / 2;
	ans -= (ll)l * (l - 1) / 2;
	return ans;
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    cin >> n;
    vi a(n);
    for(int i = 0; i < n; i++) {
    	cin >> a[i];
    	--a[i];
    	pos[a[i]].push_back(i);
    }
    for(int i = 0; i < 20; i++) {
    	pref[i].assign(pos[i].size() + 1, 0);
    	for(int j = 1; j <= pos[i].size(); j++) {
    		pref[i][j] = pref[i][j - 1] + pos[i][j - 1];
    	}
    }
    vector<ll> now(20);
    for(int i = 0; i < n; i++) {
    	for(int j = 0; j < 20; j++) {
    		left[a[i]][j] += now[j];
    	}
    	now[a[i]]++;
    }
    //cout << get_ans(0, 1) << endl;
    vector<ll> dp(1 << 20, 1000000000000000000ll);
    dp[0] = 0;
    for(int mask = 1; mask < (1 << 20); mask++) {
    	for(int i = 0; i < 20; i++) {
    		if((mask >> i) & 1) {
    			int mask1 = mask ^ (1 << i);
    			ll here = dp[mask1];
    			for(int j = 0; j < 20; j++) {
    				if(!((mask >> j) & 1)) {
    					here += left[i][j];
    				}
    			}
    			dp[mask] = min(dp[mask], here);
    		}
    	}
    }
    //cout << dp[2] << endl;
    cout << dp[(1 << 20) - 1];
}