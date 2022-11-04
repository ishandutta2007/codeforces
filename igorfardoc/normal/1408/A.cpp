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
    	vi a(n), b(n), c(n);
    	for(int i = 0; i < n; i++) {
    		cin >> a[i];
    	}
    	for(int i = 0; i < n; i++) {
    		cin >> b[i];
    	}
    	for(int i = 0; i < n; i++) {
    		cin >> c[i];
    	}
    	vi res(n);
    	res[0] = a[0];
    	cout << a[0] << ' ';
    	for(int i = 1; i < n; i++) {
    		if(i != n - 1) {
    			if(a[i] == res[i - 1]) {
    				res[i] = b[i];
    			} else {
    				res[i] = a[i];
    			}
    			cout << res[i] << ' ';
    		} else {
    			if(a[i] != res[i - 1] && a[i] != res[0]) {
    				cout << a[i] << '\n';
    			} else if(b[i] != res[i - 1] && b[i] != res[0]) {
    				cout << b[i] << '\n';
    			} else {
    				cout << c[i] << '\n';
    			}
    		}
    	}
    }
}