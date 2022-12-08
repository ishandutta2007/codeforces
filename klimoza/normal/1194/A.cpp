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

#define size(x) (x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;

const ll inf0 = 2 * 1024 * 1024 * 1023;
const ll inf = inf0 * inf0;
double eps = 1e-6;
ll mod = 1e9+ 7;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	
	int t;
	cin >> t;
	while (t--) {
		int x, n;
		cin >> n >> x;
		if (2 * x <= (2 * n - 1)) cout << 2 * x << endl;
		else cout << (2 * n) + (x - n) << endl;
	}
	return 0;
}