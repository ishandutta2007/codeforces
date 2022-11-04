#include<bits/stdc++.h>
#define inf 1000000
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
    	string s, t;
    	cin >> s >> t;
    	if(s == t) {
    		cout << "0\n";
    		continue;
    	}
    	bool all0 = true;
    	for(int i = 0; i < n; i++) {
    		if(s[i] != '0') {
    			all0 = false;
    			break;
    		}
    	}
    	if(all0) {
    		cout << "-1\n";
    		continue;
    	}
    	all0 = true;
    	for(int i = 0; i < n; i++) {
    		if(t[i] != '0') {
    			all0 = false;
    			break;
    		}
    	}
    	if(all0) {
    		cout << "-1\n";
    		continue;
    	}
    	int ans = inf;
    	// ans % 2 == 1
    	int anshere = 0;
    	int am0 = 0;
    	int am1 = 0;
    	for(int i = 0; i < n; i++) {
    		if(s[i] == t[i]) {
    			if(s[i] == '1') {
    				++am1;
    			} else {
    				++am0;
    			}
    			++anshere;
    		}
    	}
    	if(anshere % 2 == 1 && am1 == am0 + 1) {
    		ans = min(ans, anshere);
    	}
    	// ans % 2 == 0
    	anshere = 0;
    	am0 = 0;
    	am1 = 0;
    	for(int i = 0; i < n; i++) {
    		if(s[i] != t[i]) {
    			if(s[i] == '1') {
    				++am1;
    			} else {
    				++am0;
    			}
    			++anshere;
    		}
    	}
    	if(anshere % 2 == 0 && am1 == am0) {
    		ans = min(ans, anshere);
    	}
    	if(ans == inf) {
    		cout << "-1\n";
    	} else {
    		cout << ans << '\n';
    	}
    }
}