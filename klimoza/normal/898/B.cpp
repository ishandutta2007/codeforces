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
	
	ll n, a, b;
	cin >> n >> a >> b;
	for (int i = 0; i <= 1e7; i++) {
		if ((n - i * a) >= 0 && (n - i * a) % b == 0) {
			cout << "YES\n";
			cout << i << " " << (n - i * a) / b << endl;
			return 0;
		}
	}
	cout << "NO\n";
	//system("pause");
	return 0;
}