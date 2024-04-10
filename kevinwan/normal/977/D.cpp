#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll num[100];
ll num2(ll x){
	ll k = 0;
	while (x%2==0) { x /= 2; k++; }
	return k;
}
ll num3(ll x) {
	ll k = 0;
	while (x % 3 == 0) { x /= 3; k++; }
	return k;
}
bool comp(ll a, ll b) {
	if(num3(a) > num3(b))return 1;
	if (num2(a) < num2(b))return 1;
	return 0;
}
int main() {
	int n,i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)scanf("%lld", num + i);
	sort(num, num + n, comp);
	for (i = 0; i < n; i++)printf("%lld ", num[i]);
}