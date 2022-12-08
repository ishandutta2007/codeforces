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
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int ans = 0;
	for (int i = 0; i < n; i+=2) {
		ans += a[i + 1] - a[i];
	}
	cout << ans << endl;
	//system("pause");
	return 0;
}