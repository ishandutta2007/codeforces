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
    	vi a(n + 2);
    	for(int i = 0; i < n + 2; i++) {
    		cin >> a[i];
    	}
    	vi pref1(n + 3), pref2(n + 3);
    	pref1[0] = 0;
    	for(int i = 1; i <= n + 2; i++) {
    		pref1[i] = max(pref1[i - 1], a[i - 1]);
    	}
    	pref2[n + 2] = 0;
    	for(int i = n + 1; i >= 0; i--) {
    		pref2[i] = max(pref2[i + 1], a[i]);
    	}
    	ll sum = 0;
    	for(int i = 0; i < n + 2; i++) {
    		sum += a[i];
    	}
    	bool ok = false;
    	for(int i = 0; i < n + 2; i++) {
    		ll sum1 = sum - a[i];
    		int max1 = max(pref1[i], pref2[i + 1]);
    		if(sum1 == max1 * 2) {
    			bool was = false;
    			for(int j = 0; j < n + 2; j++) {
    				if(j == i) {
    					continue;
    				}
    				if(!was && a[j] == max1) {
    					was = true;
    					continue;
    				}
    				cout << a[j] << ' ';
    			}
    			cout << '\n';
    			ok = true;
    			break;
    		}
    	}
    	if(!ok) {
    		cout << "-1\n";
    	}
    }
}