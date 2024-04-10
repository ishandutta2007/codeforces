#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ll n, ans = 1;
	cin>>n; 
	for (ll i = 2; i * i <= n; i++){
		if (n % i == 0) {
			ans += n;
			n = n / i;
			i = 1;
		}
	}
	ans = ans + n;
	cout<<ans;
	return 0;
}