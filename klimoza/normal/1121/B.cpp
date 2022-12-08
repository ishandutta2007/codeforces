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
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	int l, r;
	int maxi = 0;
	int ans = 0;
	for (int i = 1; i <= 2e5; i++) {
		l = 0;
		r = n - 1;
		ans = 0;
		while (l < r) {
			if (a[l] + a[r] == i) {
				ans++;
				l++;
				r--;
			}
			else if (a[l] + a[r] < i) {
				l++;
			}
			else {
				r--;
			}
		}
		maxi = max(maxi, ans);
	}
	cout << maxi << endl;
	//system("pause");
	return 0;
}