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
    	string s;
    	cin >> s;
    	if(n % 3 != 0) {
    		cout << "NO\n";
    		continue;
    	}
    	int am1 = 0;
    	int am2 = 0;
    	bool ok = true;
    	for(int i = 0; i < n; i++) {
    		if(s[i] == 'T') {
    			++am1;
    		} else {
    			++am2;
    		}
    		if(am2 > am1) {
    			ok = false;
    		}
    	}
    	if(!ok || am1 != am2 * 2) {
    		cout << "NO\n";
    		continue;
    	}
    	am1 = 0;
    	am2 = 0;
    	for(int i = n - 1; i >= 0; i--) {
    		if(s[i] == 'T') {
    			++am1;
    		} else {
    			++am2;
    		}
    		if(am2 > am1) {
    			ok = false;
    		}
    	}
    	if(!ok) {
    		cout << "NO\n";
    	} else {
    		cout << "YES\n";
    	}
    }
}