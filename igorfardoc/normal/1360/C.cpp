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
    	int am1 = 0;
    	int am0 = 0;
    	vi am(102, 0);
    	for(int i = 0; i < n; i++) {
    		int a;
    		cin >> a;
    		++am[a];
    		if(a % 2 == 0) {
    			++am0;
    		} else {
    			++am1;
    		}
    	}
    	if(am0 % 2 == 0) {
    		cout << "YES\n";
    		continue;
    	}
    	bool ok = false;
    	for(int i = 0; i < 101; i++) {
    		if(am[i] > 0 && am[i + 1]) {
    			ok = true;
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