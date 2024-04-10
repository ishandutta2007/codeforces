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
long double eps = 1e-8;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	int t = 0;
	int r = n % (2 * k + 1);
	int fin = n;
	if (r) {
		if (r > k) {
			fin = n - (r - k);
		}
		else {
			t = (k + 1) - r;
			fin = n - 1;
		}
	}
	int cur = 0;
	int cnt = 0;
	vector<int> ans;
	for (int i = 0; i < n; i++) {
		if ((i == (k + cur + 2 * k * cur)) && ((n - i) >= (k + 1))) {
			cnt++;
			ans.push_back(i + 1 - t);
			cur++;
		}
	}
	if (r) {
		ans.push_back(fin + 1);
		cnt++;
	}
	cout << cnt << endl;
	for (int i : ans) cout << i << " ";
	cout << endl;
	//system("pause");
	return 0;
}