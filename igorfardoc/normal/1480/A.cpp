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
    	for(int i = 0; i < n; i++) {
    		if(i % 2 == 0) {
    			if(s[i] == 'a') {
    				s[i] = 'b';
    			} else {
    				s[i] = 'a';
    			}
    		} else {
    			if(s[i] == 'z') {
    				s[i] = 'y';
    			} else {
    				s[i] = 'z';
    			}
    		}
    	}
    	cout << s << '\n';
    }
}