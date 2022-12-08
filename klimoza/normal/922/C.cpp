#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <deque>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <random>

using namespace std;

typedef long long ll;

ll INF = 1e18;
int INFi = 2e9;
double eps = 1e-6;
ll mod = 1e9 + 7;

ll gcd(ll a, ll b) {
	return (b ? gcd(b, a % b) : a);
}

ll lcm(ll a, ll b) {
	return (a * b) / gcd(a, b);
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cout.precision(15);

	ll n, k; cin >> n >> k;
	if (n == 1) {
		if (k <= 2)
			cout << "Yes\n";
		else
			cout << "No\n";
	} else if (k >= n || k >= 43) {
		cout << "No\n";
	}
	else {
		ll cur = 1;
		for (int i = 2; i <= k; i++) cur = lcm(cur, i);
		if ((n + 1) % cur == 0) {
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}
	}
	//system("pause");
	return 0;
}