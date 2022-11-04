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
    	char c = 'z';
    	int n = s.size();
    	for(int i = 0; i < n; i++) {
    		c = min(c, s[i]);
    	}
    	cout << c << ' ';
    	bool was = false;
    	for(int i = 0; i < n; i++) {
    		if(s[i] == c && !was) {
    			was = true;
    			continue;
    		}
    		cout << s[i];
    	}
    	cout << '\n';
    }
}