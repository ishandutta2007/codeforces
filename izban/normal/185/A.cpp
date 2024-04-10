#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>


using namespace std;

#define sqr(x) ((x)*(x))
#define PB(a) push_back(a)
#define MP(a) make_pair(a)
#define ll long long

int gcd(int a, int b) {
	while (b) b^=a^=b^=a%=b;
	return a;
}

const int maxn=100100, mod=1000000007;

ll bin(ll x, ll p) {
	if (p==0) return 1;
	if (p==1) return x;
	ll y=bin(x,p/2);
	ll res=y*y%mod;
	if (p&1) {
		res*=x;
		res%=mod;
	}
	return res%mod;
}

ll n;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n;
	if (n==0) {
		cout << 1;
		return 0;
	}
	ll ans=bin(2,n-1)*(1+bin(2,n));
	ans%=mod;
	cout << ans;

	return 0;
}