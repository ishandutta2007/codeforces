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
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    ll res = 0;
    for(int i = 1; i < n; i++) {
    	res = _gcd(res, abs(a[i] - a[0]));
    }
    for(int i = 0; i < m; i++) {
    	ll b;
    	cin >> b;
    	cout << _gcd(res, b + a[0]) << ' ';
    }
}