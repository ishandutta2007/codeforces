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
    	int ams = 0;
    	int ame = 0;
    	for(int i = 0; i < s.size(); i++) {
    		if(s[i] == 'E') {
    			++ame;
    		} else {
    			++ams;
    		}
    	}
    	if(ams == 1) {
    		cout << "NO\n";
    	} else {
    		cout << "YES\n";
    	}
    }
}