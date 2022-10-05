#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll k, a[100010], ans;
const ll inf = 1e15;

ll fnd(ll k){
	map<ll, int> mp;
	ll ret = 0;
	for(int i = n; i >= 0; i--){
        ret += mp[a[i] + k];
		mp[a[i]]++;
	}
	return ret;
}

int main(){
	scanf("%d%lld", &n, &k);
	for(int i = 1; i <= n; i++){ scanf("%lld", a + i); a[i] += a[i - 1]; }
	if(k == 0){ printf("%lld\n", fnd(0)); return 0; }
	if(k == 1){ printf("%lld\n", fnd(1)); return 0; }
	if(k == -1){ printf("%lld\n", fnd(1) + fnd(-1)); return 0; }
	for(ll t = 1; abs(t) <= inf; t *= k) ans += fnd(t);
	printf("%lld\n", ans);
	return 0;
}