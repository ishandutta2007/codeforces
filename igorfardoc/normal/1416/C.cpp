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
    int n;
    cin >> n;
    vi a(n);
    for(int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    vvi cl(1);
    for(int i = 0; i < n; i++) {
    	cl[0].push_back(i);
    }
    int x = 0;
    ll res = 0;
    for(int i = 29; i >= 0; i--) {
    	vvi clnew;
    	ll tot1 = 0;
    	ll tot2 = 0;
    	for(const auto& b : cl) {
    		int k = b.size();
    		ll inv1 = 0;
    		ll inv2 = 0;
    		int am0 = 0;
    		int am1 = 0;
    		vi a1;
    		vi a2;
    		for(int l = 0; l < k; l++) {
    			if((a[b[l]] >> i) & 1) {
    				a1.push_back(b[l]);
    				inv1 += am0;
    				++am1;
    			} else {
    				a2.push_back(b[l]);
    				++am0;
    				inv2 += am1;
    			}
    		}
    		tot1 += inv1;
    		tot2 += inv2;
    		if(!a1.empty()) {
    			clnew.push_back(a1);
    		}
    		if(!a2.empty()) {
    			clnew.push_back(a2);
    		}
    	}
    	res += min(tot1, tot2);
    	if(tot1 < tot2) {
    		x ^= (1 << i);
    	}
    	cl = clnew;
    }
    cout << res << ' ' << x;
}