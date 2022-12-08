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
	vector<ll> a(n);
	ll su = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		su += a[i];
	}
	sort(a.begin(), a.end());
	int t;
	cin >> t;
	int f;
	for (int i = 0; i < t; i++) {
		cin >> f;
		cout << su - a[n - f] << endl;
	}
	//system("pause");
	return 0;
}