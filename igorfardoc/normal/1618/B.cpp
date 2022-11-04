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
    	vector<string> a(n - 2);
    	for(int i = 0; i < n - 2; i++) {
    		cin >> a[i];
    	}
    	string res = "";
    	bool ok = false;
    	for(int i = 0; i < n - 3; i++) {
    		if(a[i][1] == a[i + 1][0]) {
    			res += a[i][0];
    			continue;
    		} else {
    			ok = true;
    			res += a[i][0];
    			res += a[i][1];
    		}
    	}
    	res += a[n - 3][0];
    	res += a[n - 3][1];
    	if(!ok) {
    		res += "a";
    	}
    	cout << res << '\n';
    }
}