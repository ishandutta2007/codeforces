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
	
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	int ans = 0;
	int l = 0;
	int r = 0;
	int t = 0;
	vector<bool> used(n, false);
	while (r < n) {
		if (a[r] - a[l] + 1 > m) {
			if (used[l]) t--;
			l++;
			continue;
		}
		if (r - l + 1 - t == k && a[r] - a[l] + 1 <= m) {
			used[r] = true;
			t++;
			r++;
			ans++;
			continue;
		}
		r++;
	}
	cout << ans << endl;
	//system("pause");
	return 0;
}