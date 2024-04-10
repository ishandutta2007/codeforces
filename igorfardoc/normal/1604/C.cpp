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
    	vi can = {2};
    	bool ok = true;
    	for(int i = 0; i < min(n, 100); i++) {
    		bool ok1 = false;
    		for(auto el : can) {
    			if(a[i] % el != 0) {
    				ok1 = true;
    				break;
    			}
    		}
    		if(!ok1) {
    			ok = false;
    			break;
    		}
    		can.push_back(i + 3);
    	}
    	if(ok) {
    		cout << "YES\n";
    	} else {
    		cout << "NO\n";
    	}
    }
}