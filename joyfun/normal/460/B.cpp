#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <iostream>
using namespace std;

typedef long long ll;

ll a, b, c;
set<ll> ans;
ll out[105], on = 0;

ll pow1(ll x, ll k) {
	ll ans = 1;
	for (ll i = 0; i < k; i++)
		ans *= x;
	return ans;
}

bool judge(ll num, ll x) {
ll sum = 0;	
 while (num) {
		sum += num % 10;
		num /= 10;
 }
 return sum == x;
}

int main() {
	scanf("%lld%lld%lld", &a, &b, &c);
	for (ll i = 0; i <= 81; i++) {
 		ll tmp = b * pow1(i, a) + c;
 		if (tmp > 0LL && tmp < 1000000000LL && judge(tmp, i))
 			ans.insert(tmp);
 	}
 	for (set<ll>::iterator it = ans.begin(); it != ans.end(); it++)
 		out[on++] = *it;
 		printf("%lld\n", on);
	for (ll i = 0; i < on - 1; i++)
		printf("%lld ", out[i]);
	if (on)
		printf("%lld\n", out[on - 1]);
	return 0;
}