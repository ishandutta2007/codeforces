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
    	vector<string> s(n);
    	for(int i = 0; i < n; i++) {
    		cin >> s[i];
    	}
    	bool ok = true;
    	for(int i = 0; i < n - 1; i++) {
    		for(int j = 0; j < n - 1; j++) {
    			if(s[i][j] == '1' && s[i + 1][j] == '0' && s[i][j + 1] == '0') {
    				ok = false;
    			}
    		}
    	}
    	if(ok) {
    		cout << "YES\n";
    	} else {
    		cout << "NO\n";
    	}
    }
}