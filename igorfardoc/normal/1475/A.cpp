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
    	while(x % 2 == 0) {
    		x /= 2;
    	}
    	if(x == 1) {
    		cout << "NO\n";
    	} else {
    		cout << "YES\n";
    	}
    }
}