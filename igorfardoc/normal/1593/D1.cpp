#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int _gcd(int a, int b) {
	if(b == 0) {
		return a;
	}
	return _gcd(b, a % b);
}

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
    	int res = 0;
    	for(int i = 0; i < n - 1; i++) {
    		res = _gcd(res, abs(a[i] - a[i + 1]));
    	}
    	if(res == 0) {
    		cout << "-1\n";
    	} else {
    		cout << res << '\n';
    	}
    }
}