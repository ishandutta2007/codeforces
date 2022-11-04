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
    	int x, y;
    	cin >> x >> y;
    	map<char, int> am;
    	string s;
    	cin >> s;
    	int n = s.size();
    	for(int i = 0; i < n; i++) {
    		am[s[i]]++;
    	}
    	char c1 = 'L';
    	char c2 = 'D';
    	if(x >= 0) {
    		c1 = 'R';
    	}
    	if(y >= 0) {
    		c2 = 'U';
    	}
    	if(am[c1] >= abs(x) && am[c2] >= abs(y)) {
    		cout << "YES\n";
    	} else {
    		cout << "NO\n";
    	}
    }
}