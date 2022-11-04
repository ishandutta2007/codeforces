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
    	string s;
    	cin >> s;
    	bool ok = true;
    	for(int i = n - 1; i >= 0; i--) {
    		if(s[i] != ')') {
    			ok = (n - i - 1) > (i + 1);
    			break;
    		}
    	}
    	if(ok) {
    		cout << "Yes\n";
    	} else {
    		cout << "No\n";
    	}
    }
}