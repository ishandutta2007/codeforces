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
    	int m, d, w;
    	cin >> m >> d >> w;
    	int n = min(d, m);
    	ll ans = 0;
    	int c = w / _gcd(w, d - 1);
    	int last = n % c;
    	int min1 = n / c;
    	int max1 = min1 + 1;
    	if(n % c == 0) {
    		--max1;
    	}
    	ans += (ll)last * (max1) * (max1 - 1) / 2;
    	ans += (ll)(c - last) * (min1) * (min1 - 1) / 2;
    	cout << ans << '\n';
    }
}