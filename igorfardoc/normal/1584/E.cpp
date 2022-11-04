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
    int t;
    cin >> t;
    while(t--) {
    	int n;
    	cin >> n;
    	vi a(n);
    	for(int i = 0; i < n; i++) {
    		cin >> a[i];
    	}
    	multiset<ll> s;
    	map<ll, int> d;
    	ll add = 0;
    	int sign = 1;
    	ll ans = 0;
    	for(int i = 0; i < n; i++) {
    		add = a[i] - add;
    		sign = -sign;
    		if(sign > 0) {
    			while(s.size() > 0) {
    				auto it = s.begin();
    				if((*it) + add < 0) {
                        d[*it]--;
    					s.erase(it);
    					
    				} else {
    					break;
    				}
    			}
    		} else {
    			while(s.size() > 0) {
    				auto it = s.end();
    				--it;
    				if(-(*it) + add < 0) {
                        d[*it]--;
    					s.erase(it);
    					
    				} else {
    					break;
    				}
    			}
    		}
    		ll nul = add;
    		if(sign == 1) {
    			nul = -add;
    		}
    		ll to_add = (a[i] - add) / sign;
    		s.insert(to_add);
    		d[to_add]++;
    		ans += d[nul];
    	}
    	cout << ans << '\n';
    }
}