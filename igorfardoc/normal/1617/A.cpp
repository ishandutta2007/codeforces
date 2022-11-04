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
    	string s, t;
    	cin >> s >> t;
    	vi am(26);
    	for(int i = 0; i < s.size(); i++) {
    		am[s[i] - 'a']++;
    	}
    	string res = "";
    	for(int i = 0; i < am[0]; i++) {
    		res += 'a';
    	}
    	int start = 1;
    	if(t[0] == 'a' && t[1] == 'b' && am[0] > 0) {
    		for(int i = 0; i < am[2]; i++) {
	    		res += 'c';
	    	}
	    	for(int i = 0; i < am[1]; i++) {
	    		res += 'b';
	    	}
	    	start = 3;
	    }
	    for(int i = start; i < 26; i++) {
	    	for(int j = 0; j < am[i]; j++) {
	    		res += (char)(i + 'a');
	    	}
	    }
	    cout << res << '\n';
	}
}