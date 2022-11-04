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
    	if(n % 2 == 1) {
    		cout << "NO\n";
    		continue;
    	}
    	bool ok = true;
    	for(int i = 0; i < n / 2; i++) {
    		if(s[i] != s[i + n / 2]) {
    			ok = false;
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