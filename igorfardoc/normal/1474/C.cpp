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
    	n *= 2;
    	vi a(n);
    	for(int i = 0; i < n; i++) {
    		cin >> a[i];
    	}
    	sort(a.begin(), a.end());
    	bool ok = false;
    	for(int i = 0; i < n - 1; i++) {
    		vector<pair<int, int>> ans;
    		int start = 0;
    		multiset<int> s;
    		for(int j = 0; j < n; j++) {
    			if(i != j) {
    				s.insert(a[j]);
    			}
    		}
    		start = *(s.rbegin()) + a[i];
    		int now = *(s.rbegin());
    		ans.push_back({now, a[i]});
    		s.erase(--s.end());
    		while(!s.empty()) {
    			int fir = *(s.rbegin());
    			s.erase(--s.end());
    			auto it = s.find(now - fir);
    			if(it == s.end()) {
    				break;
    			}
    			ans.push_back({fir, *it});
    			now = fir;
    			s.erase(it);
    		}
    		if(ans.size() == n / 2) {
    			ok = true;
    			cout << "YES\n";
    			cout << start << '\n';
    			for(int i = 0; i < n / 2; i++) {
    				cout << ans[i].first << ' ' << ans[i].second << '\n';
    			}
    			break;
    		}
    	}
    	if(!ok) {
    		cout << "NO\n";
    	}
    }

}