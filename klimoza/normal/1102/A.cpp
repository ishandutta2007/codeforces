#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <deque>

using namespace std;

typedef long long ll;

ll INF = 1e18;

int main() {
	ll n;
	cin >> n;
	if ((n * (n + 1)) % 4 == 0) {
		cout << 0 << endl;
	}
	else {
		cout << 1 << endl;
	}
	//system("pause");
	return 0;
}