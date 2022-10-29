#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 10;
const int MM = 1e9 + 7;
typedef long long ll;
typedef pair<int, int> PII;

ll pw(ll p, ll q){
	ll ret = 1;
	for(; q; q>>=1){
		if (q & 1){
			ret = ret * p % MM;
		}
		p = p * p % MM;
	}
	return ret;
}

int main(){
	long long n, b, p;
	cin>>n>>b>>p;
	ll ans = 0, now = n * p;
	while(n != 1){
		ll m = 1;
		while(m * 2 <= n)
			m *= 2;
		ans += (2 * b + 1) * (m / 2);
		n -= m / 2;
	}
	cout<<ans<<' '<<now<<endl;
	return 0;
}