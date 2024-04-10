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

	int n;
	cin >> n;
	ll t, x;
	bool fl;
	for (int i = 0; i < n; i++) {
		cin >> t;
		if (t == 1) {
			cout << "NO\n";
			continue;
		}
		x = sqrt(t);
		if (x * x != t) {
			cout << "NO\n";
			continue;
		}
		fl = true;
		x = sqrt(x);
		for (ll j = 2; j <= x; j++) {
			if (t % j == 0) {
				cout << "NO\n";
				fl = false;
				break;
			}
		}
		if (fl) {
			cout << "YES\n";
		}
	}
	//system("pause");
	return 0;
}