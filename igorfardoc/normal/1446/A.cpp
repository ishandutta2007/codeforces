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
    	ll w;
    	cin >> n >> w;
    	ll now = 0;
    	bool ok = false;
    	vi ans;
    	for(int i = 0; i < n; i++) {
    		int a;
    		cin >> a;
    		if(ok) {
    			continue;
    		}
    		if(a > w) {
    			continue;
    		}
    		if(a >= (w - 1) / 2 + 1) {
    			ans.clear();
    			ans.push_back(i);
    			ok = true;
    		} else {
    			now += a;
    			ans.push_back(i);
    			if(now >= (w - 1) / 2 + 1) {
    				ok = true;
    			}
    		}
    	}
    	if(!ok) {
    		cout << "-1\n";
    		continue;
    	}
    	cout << ans.size() << '\n';
    	for(int i = 0; i < ans.size(); i++) {
    		cout << ans[i] + 1 << ' ';
    	}
    	cout << '\n';
    }
}