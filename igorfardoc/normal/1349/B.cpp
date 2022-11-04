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
    	int n, k;
    	cin >> n >> k;
    	vi a(n);
    	for(int i = 0; i < n; i++) {
    		cin >> a[i];
    	}
    	vi pref(n + 1, 0), pref1(n + 1, 0), suff(n + 1, 0), suff1(n + 1, 0);
    	for(int i = 1; i <= n; i++) {
    		pref[i] = pref[i - 1] + (a[i - 1] < k) - (a[i - 1] >= k);
    	}
    	for(int i = n - 1; i >= 0; i--) {
    		suff[i] = suff[i + 1] + (a[i] < k) - (a[i] >= k);
    	}
    	for(int i = 1; i <= n; i++) {
    		pref1[i] = max(pref1[i - 1], pref[i]);
    	}
    	for(int i = n - 1; i >= 0; i--) {
    		suff1[i] = max(suff1[i + 1], suff[i]);
    	}
    	if(n == 1 && a[0] == k) {
    		cout << "yes\n";
    		continue;
    	}
    	bool there = false;
    	for(int i = 0; i < n; i++) {
    		if(a[i] == k) {
    			there = true;
    			break;
    		}
    	}
    	if(!there) {
    		cout << "no\n";
    		continue;
    	}
    	bool ok = false;
    	for(int i = 0; i < n; i++) {
    		if(a[i] < k) {
    			continue;
    		}
    		if(i != 0) {
    			if(a[i - 1] >= k) {
    				ok = true;
    				break;
    			}
	    		int ammax = pref1[i - 1];
	    		int amhere = pref[i + 1];
	    		if(amhere - ammax < 0) {
	    			ok = true;
	    			break;
	    		}
	    	}
	    	if(i != n - 1) {
	    		if(a[i + 1] >= k) {
    				ok = true;
    				break;
    			}
	    		int ammax = suff1[i + 2];
	    		int amhere = suff[i];
	    		if(amhere - ammax < 0) {
	    			ok = true;
	    			break;
	    		}
	    	}
    	}
    	if(ok) {
    		cout << "yes\n";
    		continue;
    	}
    	cout << "no\n";
    }
}