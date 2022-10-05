#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ll n;
	cin >> n;
	puts("2");
	for(ll i = 2; i <= n; i++) printf("%lld\n", i * (i + 1) * (i + 1) - i + 1);
	return 0;
}