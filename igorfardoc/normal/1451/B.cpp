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
    	int n, q;
    	cin >> n >> q;
    	string s;
    	cin >> s;
    	for(int o = 0; o < q; o++) {
    		bool ok = false;
    		int l, r;
    		cin >> l >> r;
    		--l;
    		--r;
    		for(int i = r + 1; i < n; i++) {
    			if(s[i] == s[r]) {
    				ok = true;
    				break;
    			}
    		}
    		for(int i = 0; i < l; i++) {
    			if(s[i] == s[l]) {
    				ok = true;
    				break;
    			}
    		}
    		if(ok) {
    			cout << "YES\n";
    		} else {
    			cout << "NO\n";
    		}
    	}
    }
}