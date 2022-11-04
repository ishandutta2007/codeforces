#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

ll gcd(ll a, ll b) {
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
    	vector<ll> a(n);
    	for(int i = 0; i < n; i++) {
    		cin >> a[i];
    	}
    	ll d = 0;
    	for(int i = 0; i < n; i+=2) {
    		d = gcd(d, a[i]);
    	}
    	bool ok = true;
    	ll d1 = 0;
    	for(int i = 1; i < n; i+=2) {
    		d1 = gcd(d1, a[i]);
    		if(a[i] % d == 0) {
    			ok = false;
    		}
    	}
    	if(ok) {
    		cout << d << '\n';
    		continue;
    	}
    	ok = true;
    	for(int i = 0; i < n; i+=2) {
    		if(a[i] % d1 == 0) {
    			ok = false;
    			break;
    		}
    	}
    	if(ok) {
    		cout << d1 << '\n';
    	} else {
    		cout << 0 << '\n';
    	}
    }
}