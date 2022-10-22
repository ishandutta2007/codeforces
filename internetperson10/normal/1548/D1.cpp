#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, a, b, c, d; // 22, 24, 42, 44
	cin >> n;
	a = b = c = d = 0;
	for(int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		x /= 2; y /= 2;
		if(x%2 && y%2) a++;
		else if(y%2) b++;
		else if(x%2) c++;
		else d++;
	}
	ll ans = 0;
	ans = ((n-2)*(a*(a-1)+b*(b-1)+c*(c-1)+d*(d-1)))/2;
	// cout << ans << '\n';
	ans -= (a*(a-1)*(a-2))/3;
	ans -= (b*(b-1)*(b-2))/3;
	ans -= (c*(c-1)*(c-2))/3;
	ans -= (d*(d-1)*(d-2))/3;
	cout << ans << '\n';
}