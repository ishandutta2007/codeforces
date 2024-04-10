// In the name of GOD
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 100;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;

#define ll long long
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define X first
#define Y second

ll n, l, r, p[30];

int main(){
	fast_io;
	
	cin >> n >> l >> r;
	
	p[0] = 1;
	for(ll i = 1; i < 30; i++){
		p[i] = p[i - 1] * 2;
	}
	ll a = p[l] - 1 + (n - l);
	ll b = p[r] - 1 + (n - r) * p[r - 1];
	cout << a << " " << b;
	return 0;
}