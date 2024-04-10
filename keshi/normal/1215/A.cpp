//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll a, b, c, d, n, n1, n2, s1, s2;

int main(){
	fast_io;
	
	cin >> a >> b >> c >> d >> n;
	
	n1 = n;
	s1 = 0;
	s2 = 0;
	n2 = n;
	
	s1 = min(a, n1 / c);
	n1 -= s1 * c;
	s1 += min(b, n1 / d);
	
	s2 = min(b, n2 / d);
	n2 -= s2 * d;
	s2 += min(a, n2 / c);
	
	cout << max(0ll, n - a * (c - 1) - b * (d - 1)) << " " << max(s1, s2);
	
	return 0;
}