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
    	int sum = 0;
    	bool there1 = false;
    	for(int i = 0; i < n; i++) {
    		cin >> a[i];
    		if(a[i] == 1) {
    			there1 = true;
    		}
    		sum += a[i];
    	}
    	if(sum % 2 == 1) {
    		cout << "NO\n";
    		continue;
    	}
    	if(there1 || n % 2 == 0) {
    		cout << "YES\n";
    	} else {
    		cout << "NO\n";
    	}
    }
}