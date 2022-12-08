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
	
	ll n, m, k;
	cin >> n >> m >> k; k++;
	vector <ll> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	ll ans = (m / k) * ((k - 1) * a[n - 1] + a[n - 2]) + (m % k) * a[n - 1];
	cout << ans << endl;
	//system("pause");
	return 0;
}