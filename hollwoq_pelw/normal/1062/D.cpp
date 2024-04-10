#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main () {
	int n;
	cin >> n;
	ll ans=0;
	for (int i=2;i<=n;++i) {
		ll tmp = n/i;
		ans += ((tmp*(tmp+1)/2)-1)*4;
	}
	cout << ans << endl;
}