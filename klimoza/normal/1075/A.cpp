#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <deque>
#include <cmath>
#include <deque>
#include <algorithm>

using namespace std;

typedef long long int ll;

int main() {
	ll n, x, y;
	cin >> n >> x >> y;
	ll t1 = max(x - 1, y - 1);
	ll t2 = max(n - x, n - y);
	if (t1 <= t2) {
		cout << "White\n";
	}
	else {
		cout << "Black\n";
	}
	//system("pause");
	return 0;
}