#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn = 1000;

int main()
{
	ll d,k,a,b,t;
	cin >> d >> k >> a >> b >> t;
	if(k>=d){
	    cout << a*d;
	    return 0;
	}
	ll mn;
	ll n;
	ll ans;
	if(k*(b-a)>t){
		n = d - (d%k);
		ans = t*((n/k)-1)-n*(b-a);
	}else{
		n = k;
		ans = -n*(b-a);
	}
	ans = min(ans,0LL);
	ans = min(ans,t*(((d+k-1)/k)-1)-d*(b-a));
	ans += b*d;
	cout << ans;
}