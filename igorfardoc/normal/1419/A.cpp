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
    	int good = 0;
    	if(n % 2 == 0) {
    		good = 1;
    	}
    	int am0 = 0;
    	int am1 = 0;
    	for(int i = 0; i < n; i++) {
    		if(i % 2 == good) {
    			if((s[i] - '0') % 2 == 0) {
    				++am0;
    			} else {
    				++am1;
    			}
    		}
    	}
    	if(good == 0) {
    		if(am1 > 0) {
    			cout << 1 << '\n';
    		} else {
    			cout << 2 << '\n';
    		}
    	} else {
    		if(am0 > 0) {
    			cout << 2 << '\n';
    		} else {
    			cout << 1 << '\n';
    		}
    	}
    }
}