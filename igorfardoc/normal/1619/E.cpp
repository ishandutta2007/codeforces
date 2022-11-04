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
    	vi am(n + 1);
    	for(int i = 0; i < n; i++) {
    		int a;
    		cin >> a;
    		am[a]++;
    	}
    	multiset<int> s;
    	bool can = true;
    	ll ans = 0;
    	for(int i = 0; i <= n; i++) {
    		if(!can) {
    			cout << "-1 ";
    			continue;
    		}
    		cout << ans + am[i] << ' ';
    		if(am[i] > 0) {
    			for(int j = 0; j < am[i] - 1; j++) {
    				s.insert(i);
    			}
    		} else {
    			if(s.empty()) {
    				can = false;
    				continue;
    			}
    			auto it = --s.end();
    			ans += i - *it;
    			s.erase(it);
    		}
    	}
    	cout << '\n';
    }
}