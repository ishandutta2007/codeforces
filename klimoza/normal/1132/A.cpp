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

	int c1, c2, c3, c4;
	cin >> c1 >> c2 >> c3 >> c4;
	if (c1 == 0 && c3 != 0) {
		cout << 0 << endl;
	} else if (c1 == c4) {
		cout << 1 << endl;
	}
	else {
		cout << 0 << endl;
	}
	//system("pause");
	return 0;
}