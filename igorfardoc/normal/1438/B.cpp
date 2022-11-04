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
    	vi a(n);
    	for(int i = 0; i < n; i++) {
    		cin >> a[i];
    	}
    	bool ok = true;
    	set<int> s;
    	for(int i = 0; i < n; i++) {
    		if(s.find(a[i]) != s.end()) {
    			ok = false;
    			break;
    		}
    		s.insert(a[i]);
    	}
    	if(ok) {
    		cout << "NO\n";
    	} else {
    		cout << "YES\n";
    	}
    }
}