#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

ll check(int a, int b, int c, int d, ll k) {
	ll now = k * d;
	ll hp = (k + 1) * a;
	ll am = 0;
	if((ll)k * d >= c) {
		am = ((ll)k * d - c) / d + 1;
	}
	__int128 minus = (__int128)am * b * c;
	if(minus >= hp) {
		return -1;
	}
	hp -= (ll)minus;
	ll am1 = min((ll)(c - 1) / d, k);
	minus = (__int128)d * b * ((ll)am1 * (am1 + 1) / 2);
	if(minus >= hp) {
		return -1;
	}
	return hp - (ll)minus;
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
    int t;
    cin >> t;
    while(t--) {
    	int a, b, c, d;
    	cin >> a >> b >> c >> d;
    	if(a > (ll)c * b) {
    		cout << "-1\n";
    		continue;
    	}
    	ll l = 0;
    	ll r = 1000000000000ll;
    	while(r - l > 2) {
    		ll mid1 = l + (r - l) / 3;
    		ll mid2 = r - (r - l) / 3;
    		ll res1 = check(a, b, c, d, mid1);
    		ll res2 = check(a, b, c, d, mid2);
    		if(res2 <= 0 || res2 < res1) {
    			r = mid2;
    		} else {
    			l = mid1;
    		}
    	}

    	long long max1 = 0;
    	for(ll i = l; i <= r; i++) {
    		max1 = max(max1, check(a, b, c, d, i));
    	}
    	cout << max1 << '\n';
    	//cout << check(a, b, c, d, 1);
    }
}