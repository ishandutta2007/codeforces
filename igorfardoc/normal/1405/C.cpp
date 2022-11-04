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
    	string s;
    	cin >> s;
    	bool ok = true;
    	for(int i = 0; i < k; i++) {
    		bool there1 = false;
    		bool there0 = false;
    		for(int j = i; j < n; j+=k) {
    			if(s[j] == '1') {
    				there1 = true;
    			}
    			if(s[j] == '0') {
    				there0 = true;
    			}
    		}
    		if(there1 && there0) {
    			ok = false;
    			break;
    		}
    		if(!there1 && !there0) {
    			continue;
    		}
    		int need = 0;
    		if(there1) {
    			need = 1;
    		}
    		for(int j = i; j < n; j+=k) {
    			s[j] = (char)('0' + need);
    		}
    	}
    	if(!ok) {
    		cout << "NO\n";
    		continue;
    	}
    	int am0 = 0;
    	int am1 = 0;
    	int am = 0;
    	for(int i = 0; i < k; i++) {
    		if(s[i] == '1') {
    			++am1;
    		} else if(s[i] == '0') {
    			++am0;
    		} else {
    			++am;
    		}
    	}
    	if(min(am0, am1) + am >= max(am0, am1)) {
    		cout << "YES\n";
    	} else {
    		cout << "NO\n";
    	}
    }
}