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

using namespace std;

typedef long long ll;

ll INF = 4e18;
ll INFi = 2e9;
long double eps = 1e-6;
ll mod = 1e9 + 7;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cout.precision(15);
	
	int n;
	cin >> n;
	if (n % 2 == 1) cout << 0 << endl;
	else cout << (1 << (n / 2)) << endl;
	return 0;
}