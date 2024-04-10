#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

vector<int> nums;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		ll x = (1LL << 35) - 1;
		while(n--) {
			ll y;
			cin >> y;
			x &= y;
		}
		cout << x << '\n';
	}
}