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

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int ans = 0;
	sort(a.begin(), a.end());
	int l = 0;
	int r = 0;
	int cur = 0;
	while (r < n) {
		cur = r - l + 1;
		ans = max(ans, cur);
		if (r == n - 1) break;
		if (a[r + 1] - a[l] > 5) {
			l++;
		}
		else {
			r++;
		}
	}
	cout << ans << endl;
	//system("pause");
	return 0;
}