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
    	for(int i = 0; i < (n - 1) / 2 + 1; i++) {
    		if(n % 2 == 1 && i == n / 2) {
    			cout << a[i];
    			continue;
    		}
    		cout << a[i] << ' ' << a[n - 1 - i] << ' ';
    	}
    	cout << '\n';
    }
}