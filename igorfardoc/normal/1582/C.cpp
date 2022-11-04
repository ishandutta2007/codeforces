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
    	int res = 1000000;
    	for(char c = 'a'; c <= 'z'; c++) {
    		int l = 0;
    		int r = n - 1;
    		int ans = 0;
    		bool ok = true;
    		while(l < r) {
    			if(s[l] == s[r]) {
    				++l;
    				--r;
    				continue;
    			}
    			++ans;
    			if(s[l] == c) {
    				++l;
    			} else if(s[r] == c) {
    				--r;
    			} else {
    				ok = false;
    				break;
    			}
    		}
    		if(ok) {
    			res = min(res, ans);
    		}
    	}
    	if(res == 1000000) {
    		cout << "-1\n";
    	} else {
    		cout << res << '\n';
    	}
    }
}