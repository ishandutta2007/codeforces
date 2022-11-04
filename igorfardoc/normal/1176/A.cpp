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
    	ll x;
    	cin >> x;
    	int res = 0;
    	while(x % 5 == 0) {
    		x /= 5;
    		x *= 4;
    		++res;
    	}
    	while(x % 3 == 0) {
    		x /= 3;
    		x *= 2;
    		++res;
    	}
    	while(x % 2 == 0) {
    		x /= 2;
    		++res;
    	}
    	if(x == 1) {
    		cout << res << '\n';
    	} else {
    		cout << "-1\n";
    	}
    }
}