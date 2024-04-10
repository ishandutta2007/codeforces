#pragma optimise('O3');
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <deque>
#include <cassert>

using namespace std;

#define PI 3.14159265
typedef long long ll;

const ll INF = 1e18;
ll mod = 1e9 + 7;

int main() {
	int n, k;
	cin >> n >> k;
	ll ans = INF;
	for (int i = 1; i < k; i++) {
		if(n % i == 0){
			ll tmod = i;
			ll tdiv = n / i;
			ans = min(ans, tdiv * k + tmod);
		}
	}
	cout << ans << endl;
	//system("pause");
	return 0;
}