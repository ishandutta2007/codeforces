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

bool cmp(ll x, ll y) {
	return x > y;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	
	ll n, k;
	cin >> n >> k;
	if (k * (k - 1) < n) {
		cout << "NO\n";
	}
	else {
		cout << "YES\n";
		int cnt = 0;
		int m = 1;
		int g = 2;
		int type = 0;
		while (true) {
			if (cnt == n) break;
			if (g == k + 1) {
				m++;
				g = m + 1;
			}
			if (!type) {
				cout << m << " " << g << endl;
			}
			else {
				cout << g << " " << m << endl;
				g++;
			}
			type = (type + 1) % 2;
			cnt++;
		}
	}
	//system("pause");
	return 0;
}