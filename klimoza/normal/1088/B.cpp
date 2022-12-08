#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <deque>

using namespace std;


typedef long long ll;

const ll INF = 1e18;

int main() {
	int n, k;
	cin >> n >> k;
	int cur = 0;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++) {
		if (k == 0) break;
		if (a[i] <= cur) continue;
		k--;
		cout << a[i] - cur << endl;
		cur += a[i] - cur;
	}
	for (int i = 0; i < k; i++) {
		cout << "0\n";
	}
	//system("pause");
	return 0;
}