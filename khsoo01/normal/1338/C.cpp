#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

const int N = 100005;

const int X[3][4] = {
	{0, 1, 2, 3},
	{0, 2, 3, 1},
	{0, 3, 1, 2}
};
ll n, m;

void solve () {
	scanf("%lld",&n);
	n--;
	m = n%3;
	n /= 3;
	ll C = 0, D = 1;
	while(C + D <= n) {
		C += D;
		D *= 4;
	}
	n -= C;
	ll A = 0;
	for(ll i=1;i<D;i*=4) {
		A += X[m][(n/i)%4]*i;
	}
	A += D * (m+1);
	printf("%lld\n", A);
}

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--) solve();
}