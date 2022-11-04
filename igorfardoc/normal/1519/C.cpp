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
    	vvi a(n);
    	vi b(n);
    	ll sum = 0;
    	for(int i = 0; i < n; i++) {
    		cin >> b[i];
    	}
    	for(int i = 0; i < n; i++) {
    		int s;
    		cin >> s;
    		sum += s;
    		a[b[i] - 1].push_back(s);
    	}
    	vector<vector<ll>> pref(n);
    	for(int i = 0; i < n; i++) {
    		sort(a[i].begin(), a[i].end());
    		pref[i].resize(a[i].size() + 1);
    		pref[i][0] = 0;
    		for(int j = 1; j < a[i].size() + 1; j++) {
    			pref[i][j] = pref[i][j - 1] + a[i][j - 1];
    		}
    	}
    	vector<int> now;
    	for(int i = 0; i < n; i++) {
    		if(a[i].size() != 0) {
    			now.push_back(i);
    		}
    	}
    	for(int k = 1; k <= n; k++) {
    		ll res = sum;
    		vi new1;
    		for(int i = 0; i < now.size(); i++) {
    			int here = now[i];
    			res -= pref[here][a[here].size() % k];
    			if(a[here].size() == k) {
    				sum -= pref[here][a[here].size()];
    			} else {
    				new1.push_back(here);
    			}
    		}
    		cout << res << ' ';
    		now = new1;
    	}
    	cout << '\n';
    }
}