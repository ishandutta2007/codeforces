#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <deque>

using namespace std;

#define PI 3.14159265
typedef long long ll;

const ll INF = 1e18;
ll mod = 1e9 + 7;

int main() {
	ll n;
	cin >> n;
	set<ll> f;
	f.insert(1);
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			ll ans = 0;
			ans = (n / i - 1) * n / 2 + n / i;
			f.insert(ans);
			//cout << i << " " << ans << endl;
			ans = (i - 1) * n / 2 + i;
			f.insert(ans);
			//cout << n/i << " " << ans << endl;
		}
	}
	while (!f.empty()) {
		cout << *f.begin() << " ";
		f.erase(f.begin());
	}
	//system("pause");
	return 0;
}