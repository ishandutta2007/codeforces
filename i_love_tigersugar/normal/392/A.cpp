#include<bits/stdc++.h>
#define FOR(i,a,b) for (ll i=(a);i<=(b);i=i+1)
#define REP(i,n) for (ll i=0;i<(n);i=i+1)
using namespace std;
typedef long long ll;
ll tructsqrt(ll x,ll p) {
	while (p*p>x) p--;
	return (p);
}
int main(void) {	
	ll n;
	cin >> n;
	if (n==0) {
		cout << 1;
		return 0;
	}
	ll prev=n;
	ll res=0;
	FOR(x,1,n) {
		ll t=tructsqrt(n*n-x*x,prev);
		assert(t<=prev);
		if (t==prev) res++;
		else res+=prev-t;
		prev=t;
	}
	cout << res*4;
	return 0;
}