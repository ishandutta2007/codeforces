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
    	int n, m;
    	cin >> n >> m;
    	bool ok = false;
    	for(int i = 0; i < n; i++) {
    		int a, b, c, d;
    		cin >> a >> b >> c >> d;
    		if(b == c) {
    			ok = true;
    		}
    	}
    	if(m % 2 == 0 && ok) {
    		cout << "YES\n";
    	} else {
    		cout << "NO\n";
    	}
    }
}