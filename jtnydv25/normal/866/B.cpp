#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 1e6 + 10;
int s[N], a[N], b[N];
ll cnt1[N], cnt2[N];
ll sz1 = 0, sz2 = 0;
ll getceil(ll a, ll b){
	if(a == 0) return 0;
	return (a - 1) / b + 1;
}
int main(){
	int n, S;
	scanf("%d %d", &n, &S);

	long long ans = 0, total= 0;

	for(int i = 1; i <= n; i++){
		scanf("%d %d %d", &s[i], &a[i], &b[i]);
		if(a[i] > b[i]) cnt1[a[i] - b[i]] += s[i], sz1 += s[i];
		else cnt2[b[i] - a[i]] += s[i], sz2 += s[i];
		ans += max(a[i], b[i]) * 1ll * s[i];
		total += s[i];
	}

	long long req = getceil(total, S);
	ll req1 = getceil(sz1, S), req2 = getceil(sz2, S);

	if(req1 + req2 == req){
		printf("%lld\n", ans);
		return 0;
	}

	// Case 1 : reduce req1
	ll res = 0;
	if(req1){
		ll ans2 = ans;
		ll change = -(req1 - 1) * S + sz1;
		for(int i = 0; i < N && change > 0; i++){
			ll x = min(change, cnt1[i]);
			change -= x;
			ans2 -= x * i;
		}
		res = max(res, ans2);
	}

	if(req2){
		ll ans2 = ans;
		ll change = -(req2 - 1) * S + sz2;
		for(int i = 0; i < N && change > 0; i++){
			ll x = min(change, cnt2[i]);
			change -= x;
			ans2 -= x * i;
		}
		res = max(res, ans2);
	}
	printf("%lld\n", res);
}