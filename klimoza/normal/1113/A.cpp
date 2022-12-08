#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <deque>
#include <cassert>
#include <math.h>
#include <random>

using namespace std;

#define PI 3.14159265
typedef long long ll;

const ll INF = 4 * 1e18;
const int INFi = 2 * 1e9;
ll mod = 1e9 + 7;


int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int n, v;
	cin >> n >> v;
	if (v >= (n - 1)) cout << n - 1 << endl;
	else {
		int ans = v - 1;
		n -= v;
		ans += n * (n + 1) / 2;
		cout << ans << endl;
	}
	//system("pause");
	return 0;
}