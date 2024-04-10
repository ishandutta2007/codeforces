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
    	vvi a(n, vi(5));
    	for(int i = 0; i < n; i++) {
    		for(int j = 0; j < 5; j++) {
    			cin >> a[i][j];
    		}
    	}
    	bool ok = false;
    	for(int a1 = 0; a1 < 5; a1++) {
    		for(int a2 = a1 + 1; a2 < 5; a2++) {
    			int am1 = 0;
    			int am2 = 0;
    			int am = 0;
    			for(int i = 0; i < n; i++) {
    				if(a[i][a1] == 1 && a[i][a2] == 1) {
    					++am;
    				} else if(a[i][a1] == 1) {
    					++am1;
    				} else if(a[i][a2] == 1) {
    					++am2;
    				}
    			}
    			if(am1 + am2 + am != n) {
    				continue;
    			}
    			if(abs(am1 - am2) <= am) {
    				cout << "YES\n";
    				ok = true;
    				break;
    			}
    		}
    		if(ok) {
    			break;
    		}
    	}
    	if(!ok) {
    		cout << "NO\n";
    	}
    }
}