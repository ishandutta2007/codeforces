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

	int n, k;
	cin >> n >> k;
	vector<int> cnt(k);
	int ans = 0;
	int t;
	for (int i = 0; i < n; i++) {
		cin >> t;
		if (t % k == 0 && cnt[0] > 0) {
			cnt[0]--;
			ans++;
		}
		else if (t % k == 0 && cnt[0] == 0) {
			cnt[0]++;
		}
		else if (t % k == (k / 2) && k % 2 == 0 && cnt[k / 2] > 0) {
			cnt[k / 2]--;
			ans++;
		}
		else if (t % k == (k / 2) && k % 2 == 0 && cnt[k / 2] == 0) {
			cnt[k / 2]++;
		}
		else if (cnt[k - (t % k)] > 0) {
			cnt[k - (t % k)]--;
			ans++;
		}
		else {
			cnt[t % k]++;
		}
	}
	cout << 2 * ans << endl;
	//system("pause");
	return 0;
}