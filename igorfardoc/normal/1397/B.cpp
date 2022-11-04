#include<bits/stdc++.h>
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
    ll cost = 1000000000000000000ll;
    int n;
    cin >> n;
    vi a(n);
    for(int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    sort(a.begin(), a.end());
    for(int i = 1;; i++) {
    	ll now = 1;
    	ll ansnow = 0;
    	bool ok = true;
    	for(int j = 0; j < n; j++) {
    		if(ansnow + now - a[j] > cost) {
    			ok = false;
    			break;
    		}
    		ansnow += abs(now - a[j]);
    		if(j == n - 1) {
    			break;
    		}
    		if((__int128)now * i > cost + 1000000000) {
    			ok = false;
    			break;
    		}
    		now *= i;
    	}
    	if(ok) {
    		cost = min(cost, ansnow);
    	} else {
    		break;
    	}
    }
    cout << cost;
}