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
    	int a, b;
    	cin >> a >> b;
    	string s;
    	cin >> s;
    	int n = s.size();
    	int res = 0;
    	int prev = -1;
    	bool was1 = false;
    	for(int i = 0; i < n; i++) {
    		if(s[i] == '0') {
    			if(prev == -1) {
    				prev = i;
    			}
    			continue;
    		}
    		if(i == 0 || s[i - 1] == '0') {
    			res += a;
    		}
    		if(!was1) {
    			was1 = true;
    		} else {
    			if(prev != -1 && (i - prev) * b < a) {
    				res -= a - (i - prev) * b;
    			}
    		}
    		prev = -1;
    	}
    	cout << res << '\n';
    }
}