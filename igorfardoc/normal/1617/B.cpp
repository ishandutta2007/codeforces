#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int gcd(int a, int b) {
	if(b == 0) {
		return a;
	}
	return gcd(b, a % b);
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
    	if(n % 2 == 0) {
    		cout << n / 2 << ' ' << n / 2 - 1 << " 1\n";
    		continue;
    	}
    	for(int i = 2; i <= n; i++) {
    		if(gcd(i, n - i - 1) == 1) {
    			cout << i << ' ' << n - i - 1 << ' ' << 1 << '\n';
    			break;
    		}
    	}
    }
}