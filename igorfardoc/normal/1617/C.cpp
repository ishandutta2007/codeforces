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
    	multiset<int> s;
    	for(int i = 0; i < n; i++) {
    		int a;
    		cin >> a;
    		s.insert(a);
    	}
    	int ans = 0;
    	bool ok = true;
    	for(int i = n; i > 0; i--) {
    		auto it = s.find(i);
    		if(it != s.end()) {
    			s.erase(it);
    			continue;
    		}
    		it = s.upper_bound(i * 2);
    		if(it == s.end()) {
    			ok = false;
    			break;
    		}
    		++ans;
    		s.erase(it);
    	}
    	if(!ok) {
    		cout << -1 << '\n';
    	} else {
    		cout << ans << '\n';
    	}
    }
}