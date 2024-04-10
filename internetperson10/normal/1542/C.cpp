#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll MOD = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		ll n, ans = 0;
		cin >> n; // 2 3 2 3 2 4 2 3 2 3
		for(int i = 2; i < 45; i++) {
			ll n2;
			if(i == 2 || i == 4 || i == 8 || i == 16 || i == 32) {
				n2 = n/2;
				ans += (i * (n - n2));
				n = n2;
			}
			else if(i == 3 || i == 9 || i == 27) {
				n2 = n/3;
				ans += (i * (n - n2));
				n = n2;
			}
			else if(i == 5 || i == 25) {
				n2 = n/5;
				ans += (i * (n - n2));
				n = n2;
			}
			else if(i == 7 || i == 11 || i == 13 || i == 17 || i == 19 || i == 23 || i == 29 || i == 31 || i == 37 || i == 41 || i == 43) {
				n2 = n/i;
				ans += (i * (n - n2));
				n = n2;
			}
			ans %= MOD;
			if(n == 0) break;
		}
		cout << ans << '\n';
	}
}