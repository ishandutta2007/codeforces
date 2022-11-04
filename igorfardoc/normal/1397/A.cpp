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
    	vi am(26);
    	for(int i = 0; i < n; i++) {
    		string s;
    		cin >> s;
    		for(int j = 0; j < s.size(); j++) {
    			++am[s[j] - 'a'];
    		}
    	}
    	bool ok = true;
    	for(int el : am) {
    		if(el % n != 0) {
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