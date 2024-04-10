#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>


using namespace std;

#define sqr(x) ((x)*(x))
#define PB(a) push_back(a)
#define MP(a) make_pair(a)
#define ll long long

ll n,k;
string s;

bool f(ll x) {
	ll ans=x;
	while (x) {
		ans+=x/k;
		x/=k;
	}
	return ans>=n;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n >> k;
	ll l=0, r=(int)1e11;
	while (r-l>1) {
		ll m=(l+r)>>1;
		if (f(m)) r=m;
		else l=m;
	}
	if (f(l)) cout << l;
	else cout << r;
	return 0;
}