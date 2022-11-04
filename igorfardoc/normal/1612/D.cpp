#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

ll _gcd(ll a, ll b) {
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
    	ll a, b, x;
    	cin >> a >> b >> x;
    	bool ok = false;
    	if(x % _gcd(a, b) != 0) {
    		cout << "NO\n";
    		continue;
    	}
    	ll d = _gcd(a, b);
    	x /= d;
    	a /= d;
    	b /= d;
    	while(true) {
    		if(a == x || b == x || x == abs(a - b)) {
    			ok = true;
    			break;
    		}
    		if(x > a && x > b) {
    			break;
    		}
    		if(a > b) {
    			swap(a, b);
    		}
    		a = min(a, abs(a - b));
    		if(x >= a && (b - x) % a == 0) {
    			ok = true;
    			break;
    		}
    		b = b - (b - a) / a * a;
    		b -= a;
    	}
    	if(ok) {
    		cout << "YES\n";
    	} else {
    		cout << "NO\n";
    	}
    }
}