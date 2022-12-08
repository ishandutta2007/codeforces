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
long double eps = 1e-8;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	
	int n, a, b;
	cin >> n >> a >> b;
	vector<int> f(n);
	for (int i = 0; i < n; i++) {
		cin >> f[i];
	}
	int ans = 0;
	for (int i = 0; i < n / 2; i++) {
		if (f[i] == 2 && f[n - i - 1] == 2) {
			ans += 2 * min(a, b);
		}
		else if (f[i] == 2 || f[n - i - 1] == 2) {
			if (f[i] == 0 || f[n - i - 1] == 0) ans += a;
			else ans += b;
		}
		else if (f[i] != f[n - i - 1]){
			cout << -1 << endl;
			return 0;
		}
	}
	if (n % 2 == 1 && f[n / 2] == 2) ans += min(a, b);
	cout << ans << endl;
	//system("pause");
	return 0;
}