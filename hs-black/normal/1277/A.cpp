#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
ll T, n;
int main() {
	cin >> T;
	while (T--) {
		cin >> n;
		ll ans = 0;
		for (ll i = 1;i <= 9; i++) {
			ll tmp = i;
			for (int k = 1;k <= 900; k++) {
				if (tmp <= n) ans++;
				else break;
				tmp = tmp * 10 + i;
			}
		}
		cout << ans << endl;
	}
	return 0;
}