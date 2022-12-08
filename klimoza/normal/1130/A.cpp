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
ll mod = 998244353;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int cnt1 = 0;
	int cnt2 = 0;
	int t;
	for (int i = 0; i < n; i++) {
		cin >> t;
		if (t > 0) cnt1++;
		else if (t < 0) cnt2++;
	}
	if (cnt1 >= (n + 1) / 2) {
		cout << 1 << endl;
	}
	else if (cnt2 >= (n + 1) / 2) {
		cout << -1 << endl;
	}
	else {
		cout << 0 << endl;
	}
	//system("pause");
	return 0;
}