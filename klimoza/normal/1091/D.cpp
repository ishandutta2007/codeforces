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
ll mod = 998244353;

int main() {
	ll n;
	cin >> n;
	ll ans = n - 1;
	for (int i = 2; i <= n; i++) {
		ans = (i * ans - 1) % mod;
	}
	ans++;
	cout << ans << endl;
	//system("pause");
	return 0;
}