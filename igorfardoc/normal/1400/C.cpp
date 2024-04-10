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
    	string s;
    	cin >> s;
    	int n = s.size();
    	int x;
    	cin >> x;
    	string w = "";
    	for(int i = 0; i < n; i++) {
    		w += '1';
    	}
    	for(int i = 0; i < n; i++) {
    		if(s[i] == '0') {
    			if(i - x >= 0) {
    				w[i - x] = '0';
    			}
    			if(i + x < n) {
    				w[i + x] = '0';
    			}
    		}
    	}
    	bool ok = true;
    	for(int i = 0; i < n; i++) {
    		bool here0 = true;
    		if(i - x >= 0 && w[i - x] == '1') {
    			here0 = false;
    		}
    		if(i + x < n && w[i + x] == '1') {
    			here0 = false;
    		}
    		if((here0 && s[i] == '1') || (!here0 && s[i] == '0')) {
    			ok = false;
    			break;
    		}
    	}
    	if(!ok) {
    		cout << -1 << '\n';
    		continue;
    	}
    	cout << w << '\n';
    }
}