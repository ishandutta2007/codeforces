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

	ll w1, h1, w2, h2;
	cin >> w1 >> h1 >> w2 >> h2;
	cout << w1 + 2 * h1 + 2 + (w1 - w2 + 1) + 2 * h2 - 1 + w2 + 2 << endl;
	//system("pause");
	return 0;
}