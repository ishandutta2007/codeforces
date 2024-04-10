#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n;

vector<ll> v;

ll val (ll I) {
	return (n/I) + (n/I)*(n/I-1)/2*I;
}

int main()
{
	scanf("%lld",&n);
	for(ll i=1;i*i<=n;i++) {
		if(n%i != 0) continue;
		v.push_back(val(i));
		if(i*i != n) v.push_back(val(n/i));
	}
	sort(v.begin(), v.end());
	for(auto &T : v) {
		printf("%lld ",T);
	}
}