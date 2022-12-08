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
	int n, x, y;
	cin >> n >> x >> y;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	if (x > y) {
		cout << n << endl;
	}
	else {
		int cnt = 0;
		for (int i : a) {
			if (x >= i) cnt++;
		}
		cout << (cnt + 1) / 2 << endl;
	}
	//system("pause");
	return 0;
}