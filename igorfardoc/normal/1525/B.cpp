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
    	bool all1 = true;
    	for(int i = 0; i < n; i++) {
    		all1 = all1 && (a[i] == i + 1);
    	}
    	if(all1) {
    		cout << "0\n";
    		continue;
    	}
    	if(a[0] == 1 || a[n - 1] == n) {
    		cout << "1\n";
    		continue;
    	}
    	if(a[0] == n && a[n - 1] == 1) {
    		cout << "3\n";
    		continue;
    	}
    	cout << "2\n";
    }
}