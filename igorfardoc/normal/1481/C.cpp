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
    	int n, m;
    	cin >> n >> m;
    	map<int, int> s;
    	set<pair<int, int>> pos;
    	vi a(n), b(n), c(m);
    	for(int i = 0; i < n; i++) {
    		cin >> a[i];
    	}
    	for(int i = 0; i < n; i++) {
    		cin >> b[i];
    		s[b[i]] = i;
    		if(a[i] != b[i]) {
    			pos.insert({b[i], i});
    		}
    	}
    	vi ans(m, -1);
    	int lastbad = -1;
    	for(int i = 0; i < m; i++) {
    		int c;
    		cin >> c;
    		auto it = pos.lower_bound({c, -1});
    		if(it == pos.end() || (*it).first != c) {
    			if(s.find(c) == s.end()) {
    				lastbad = i;
    			} else {
    				ans[i] = s[c];
    			}
    			continue;
    		}
    		ans[i] = (*it).second;
    		pos.erase(it);
    	}
    	if(!pos.empty() || lastbad == m - 1) {
    		cout << "NO\n";
    		continue;
    	}
    	cout << "YES\n";
    	for(int i = m - 2; i >= 0; i--) {
    		if(ans[i] == -1) {
    			ans[i] = ans[i + 1];
    		}
    	}
    	for(int i = 0; i < m; i++) {
    		cout << ans[i] + 1 << ' ';
    	}
    	cout << '\n';
    }
}