#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		ll n, a, b;
		cin >> n >> a >> b;
		if(a == 1) {
			if(n%b == a%b) cout << "Yes\n";
			else cout << "No\n";
		}
		else {
			ll k = 1;
			bool sad = true;
			while(k <= n) {
				if((n-k)%b == 0) sad = false;
				k *= a;
			}
			cout << ((sad) ? "No\n" : "Yes\n");
		}
	}
}