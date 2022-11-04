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
    	string s, t;
    	int n;
    	cin >> n;
    	cin >> s >> t;
    	vi am(26, 0);
    	for(int i = 0; i < n; i++) {
    		++am[s[i] - 'a'];
    		--am[t[i] - 'a'];
    	}
    	bool ok = true;
    	for(int i = 0; i < 26; i++) {
    		if(am[i] != 0) {
    			ok = false;
    			break;
    		}
    	}
    	if(!ok) {
    		cout << -1 << '\n';
    		continue;
    	}
    	int ans = 1;
    	for(int l = 0; l < n; l++) {
    		int now = l;
    		for(int i = 0; i < n; i++) {
    			if(now != n && t[now] == s[i]) {
    				++now;
    			}
    		}
    		ans = max(ans, now - l);
    	}
    	cout << n - ans << '\n';
    }
}