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
	vector<int> a(n);
	int l = 0;
	int r = 1e9;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	deque<int> ans;
	ans.push_back(a[0]);
	for (int i = 1; i < n; i++) {
		if (i % 2 == 1) {
			ans.push_back(a[i]);
		}
		else {
			ans.push_front(a[i]);
		}
	}
	while (!ans.empty()) {
		cout << ans.front() << " ";
		ans.pop_front();
	}
	//system("pause");
	return 0;
}