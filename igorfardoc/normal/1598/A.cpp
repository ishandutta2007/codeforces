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
    	string s1, s2;
    	cin >> s1 >> s2;
    	bool ok = false;
    	for(int i = 0; i < n; i++) {
    		if(s1[i] == s2[i] && s1[i] == '1') {
    			cout << "NO\n";
    			ok = true;
    			break;
    		}
    	}
    	if(!ok) {
    		cout << "YES\n";
    	}
    }
}