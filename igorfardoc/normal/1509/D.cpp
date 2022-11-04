#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

string get_sub(string& a, int l, int r) {
	string res = "";
	for(int i = l; i <= r; i++) {
		res += a[i];
	}
	return res;
}

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
    	vector<string> s(3);
    	cin >> s[0] >> s[1] >> s[2];
    	bool ok = false;
    	for(char c = '0'; c <= '1'; c++) {
    		for(int i = 0; i < 3; i++) {
    			for(int j = i + 1; j < 3; j++) {
    				string s1 = s[i];
    				string s2 = s[j];
    				int am1 = 0;
    				int am2 = 0;
    				vector<int> pos1, pos2;
    				for(int k = 0; k < 2 * n; k++) {
    					if(s1[k] == c) {
    						++am1;
    						pos1.push_back(k);
    					}
    					if(s2[k] == c) {
    						++am2;
    						pos2.push_back(k);
    					}
    				}
    				if(am1 < n || am2 < n) {
    					continue;
    				}
    				ok = true;
    				string res = "";
    				int prev1 = 0;
    				int prev2 = 0;
    				for(int i = 0; i < n; i++) {
    					res += get_sub(s1, prev1, pos1[i] - 1);
    					prev1 = pos1[i] + 1;
    					res += get_sub(s2, prev2, pos2[i] - 1);
    					prev2 = pos2[i] + 1;
    					res += c;
    				}
    				res += get_sub(s1, prev1, 2 * n - 1);
    				res += get_sub(s2, prev2, 2 * n - 1);
    				cout << res << '\n';
    				break;
    			}
    			if(ok) {
    				break;
    			}
    		}
    		if(ok) {
    			break;
    		}
    	}
    }

}