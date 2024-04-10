#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

ll k, l, r, t, x, y;
map<ll, bool> mp;

int main(){
	scanf("%lld%lld%lld%lld%lld%lld", &k, &l, &r, &t, &x, &y);
	if(y <= x){
		if(k + y > r) k -= x, t--;
		if(k < l) return printf("No"), 0;
		printf(k - (__int128)t * (x - y) >= l ? "Yes" : "No");
		return 0;
	}
	mp[k % x] = true;
	while(1){
		ll cnt = (k - l) / x;
		t -= cnt;
		k -= cnt * x;
		if(t <= 0) return printf("Yes"), 0;
		if(k + y > r) return printf("No"), 0;
		k += y;
		if(mp[k % x]) return printf("Yes"), 0;
		mp[k % x] = true;
	}
}